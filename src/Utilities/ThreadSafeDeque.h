// Copyright (c) 2018-2019, The TurtleCoin Developers
// 
// Please see the included LICENSE file for more information.

#pragma once

#include <condition_variable>

#include <mutex>

#include <queue>

template <typename T>
class ThreadSafeDeque
{
    public:
        ThreadSafeDeque() :
            m_shouldStop(false)
        {
        }

        ThreadSafeDeque(bool startStopped) :
            m_shouldStop(startStopped)
        {
        }

        bool push_back(T item)
        {
            /* Aquire the lock */
            std::unique_lock<std::mutex> lock(m_mutex);
			
            /* Stopping, don't push data */
            if (m_shouldStop)
            {
                return false;
            }

            /* Add the item to the front of the queue */
            m_deque.push_back(item);

            /* Unlock the mutex before notifying, so it doesn't block after
               waking up */
            lock.unlock();

            /* Notify the consumer that we have some data */
            m_haveData.notify_all();

            return true;
        }

        /* Delete the front item from the queue */
        void pop_front()
        {
            /* Aquire the lock */
            std::unique_lock<std::mutex> lock(m_mutex);

            /* Whilst we could allow deleting from an empty queue, i.e, waiting
               for an item, then removing it, this could cause us to be stuck
               waiting on data to arrive when the queue is empty. We can't
               really return without removing the item. We could return a bool
               saying if we completed it, but then the user has no real way to
               force a removal short of running it in a while loop.
               Instead, if we just force the queue to have to have data in,
               we can make sure a removal always suceeds. */
            if (m_deque.empty())
            {
                throw std::runtime_error("Cannot remove from an empty queue!");
            }

            /* Remove the first item from the queue */
            m_deque.pop_front();

            /* Unlock the mutex before notifying, so it doesn't block after
               waking up */
            lock.unlock();

            m_consumedData.notify_all();
        }

        /* Take an item from the front of the queue, and do NOT remove it */
        T front()
        {
            return getFirstItem(false);
        }

        /* Take and remove an item from the front of the queue */
        T front_and_remove()
        {
            return getFirstItem(true);
        }

        /* Stop the queue if something is waiting on it, so we don't block
           whilst closing */
        void stop()
        {
            /* Make sure the queue knows to return */
            m_shouldStop = true;

            /* Wake up anything waiting on data */
            m_haveData.notify_all();

            /* Make sure not to call .unlock() on the mutex here - it's
               undefined behaviour if it isn't locked. */

            m_consumedData.notify_all();
        }

        void start()
        {
            m_shouldStop = false;
        }

        size_t size()
        {
            /* Aquire the lock (I'm not sure if this is actually needed here,
               but hey) */
            std::unique_lock<std::mutex> lock(m_mutex);

            return m_deque.size();
        }

        /* Takes n elements, if available, starting at the head of the queue.
           Otherwise returns max available. Does not remove items from the queue. */
        std::vector<T> pop_front_n(const size_t numElements)
        {
            /* Aquire the lock */
            std::unique_lock<std::mutex> lock(m_mutex);

            std::vector<T> results;

            if (m_deque.size() <= numElements)
            {
                results.resize(m_deque.size());
                std::copy(m_deque.begin(), m_deque.end(), results.begin());
            }
            else
            {
                results.resize(numElements);
                std::copy(m_deque.begin(), m_deque.begin() + numElements, results.begin());
            }

            return results;
        }

    private:
        T getFirstItem(bool removeFromQueue)
        {
            /* Aquire the lock */
            std::unique_lock<std::mutex> lock(m_mutex);
			
            T item;

            /* Stopping, don't return data */
            if (m_shouldStop)
            {
                return item;
            }
                
            /* Wait for data to become available (releases the lock whilst
               it's not, so we don't block the producer) */
            m_haveData.wait(lock, [&]
            { 
                /* Stopping, don't block */
                if (m_shouldStop)
                {
                    return true;
                }

                return !m_deque.empty();
            });

            /* Stopping, don't return data */
            if (m_shouldStop)
            {
                return item;
            }

            /* Get the first item in the queue */
            item = m_deque.front();

            /* Remove the first item from the queue */
            if (removeFromQueue)
            {
                m_deque.pop_front();
            }

            /* Unlock the mutex before notifying, so it doesn't block after
               waking up */
            lock.unlock();

            m_consumedData.notify_all();
			
            /* Return the item */
            return item;
        }
        
    private:
        /* The deque data structure */
        std::vector<T> m_deque;

        /* The mutex, to ensure we have atomic access to the queue */
        std::mutex m_mutex;

        /* Whether we have data or not */
        std::condition_variable m_haveData;

        /* Triggered when data is consumed */
        std::condition_variable m_consumedData;

        /* Whether we're stopping */
        std::atomic<bool> m_shouldStop;
};
