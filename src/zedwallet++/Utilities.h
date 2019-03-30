// Copyright (c) 2018, The TurtleCoin Developers
// 
// Please see the included LICENSE file for more information.

#pragma once

#include <algorithm>

#include <memory>

#include <string>

#include <vector>

#include <WalletBackend/WalletBackend.h>

namespace ZedUtilities
{

void confirmPassword(
    const std::shared_ptr<WalletBackend> walletBackend,
    const std::string msg);

bool confirm(const std::string &msg);
bool confirm(const std::string &msg, const bool defaultReturn);

std::string unixTimeToDate(const uint64_t timestamp);

uint64_t getScanHeight();

template <typename T, typename Function>
std::vector<T> filter(const std::vector<T> &input, Function predicate)
{
    std::vector<T> result;

    std::copy_if(
        input.begin(), input.end(), std::back_inserter(result), predicate
    );

    return result;
}

} // namespace
