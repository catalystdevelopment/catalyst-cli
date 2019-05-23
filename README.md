![Imgur Image](https://i.imgur.com/SF4M5F5.png)

#### v0.0.1.0 November 25, 2018
#### v0.0.1.1 November 27, 2018
#### v0.2.0.0 December 8, 2018

www.cryptocatalyst.net

Discord (most active here)
https://discord.gg/rd3ss4G

<!--
#### Master Build Status
[![Build Status](https://travis-ci.org/turtlecoin/turtlecoin.svg?branch=master)](https://travis-ci.org/turtlecoin/turtlecoin) [![Build status](https://ci.appveyor.com/api/projects/status/github/turtlecoin/turtlecoin?branch=master&svg=true)](https://ci.appveyor.com/project/RocksteadyTC/turtlecoin)
-->
#### Development Build Status
[![Build Status](https://travis-ci.org/turtlecoin/turtlecoin.svg?branch=development)](https://travis-ci.org/dirtybits/catalyst) [![Build status](https://ci.appveyor.com/api/projects/status/github/catalystdevelopment/catalyst?branch=development&svg=true)](https://ci.appveyor.com/project/dirtybits/catalyst)

### Installing
<!--
Pre-compiled Windows executables are available here: https://github.com/dirtybits/catalyst-executables/blob/master/Release_fixed.zip
We offer binary images of the latest releases here: https://latest.turtlecoin.lol
-->
If you would like to compile yourself, read on.

### How To Compile

#### Build Optimization

The CMake build system will, by default, create optimized *native* builds for your particular system type when you build the software. Using this method, the binaries created provide a better experience and all together faster performance.

However, if you wish to create *portable* binaries that can be shared between systems, specify `-DARCH=default` in your CMake arguments during the build process. Note that *portable* binaries will have a noticable difference in performance than *native* binaries. For this reason, it is always best to build for your particuar system if possible.

#### Linux

##### Prerequisites

You will need the following packages: [Boost](https://www.boost.org/), [OpenSSL](https://www.openssl.org/), cmake (3.8 or higher), make, and git.

You will also need either GCC/G++, or Clang.

If you are using GCC, you will need GCC-7.0 or higher.

If you are using Clang, you will need Clang 6.0 or higher. You will also need libstdc++\-6.0 or higher.

##### Ubuntu, using GCC

- `sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y`
- `sudo apt-get update`
- `sudo apt-get install aptitude -y`
- `sudo aptitude install -y build-essential g++-8 gcc-8 git libboost-all-dev python-pip libssl-dev`
- `sudo pip install cmake`
- `export CC=gcc-8`
- `export CXX=g++-8`
- `git clone https://github.com/catalystdevelopment/catalyst` 
<!--
- `git clone -b master --single-branch https://github.com/catalystdevelopment/cryptocatalyst`
-->
- `cd catalyst`
- `mkdir build`
- `cd build`
- `cmake ..`
- `make`
- You can also run `make` with multiple threads to speed up the build process like so:
- `make -j<number of threads>`

The binaries will be in the `src` folder when you are complete.

- `cd src`
- `./Catalystd --version`

##### Ubuntu, using Clang

- `sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y`
- `wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -`

You need to modify the below command for your version of ubuntu - see https://apt.llvm.org/

* Ubuntu 14.04 (Trusty)
- `sudo add-apt-repository "deb https://apt.llvm.org/trusty/ llvm-toolchain-trusty 6.0 main"`

* Ubuntu 16.04 (Xenial)
- `sudo add-apt-repository "deb https://apt.llvm.org/xenial/ llvm-toolchain-xenial 6.0 main"`

* Ubuntu 18.04 (Bionic)
- `sudo add-apt-repository "deb https://apt.llvm.org/bionic/ llvm-toolchain-bionic 6.0 main"`

- `sudo apt-get update`
- `sudo apt-get install aptitude -y`
- `sudo aptitude install -y -o Aptitude::ProblemResolver::SolutionCost='100*canceled-actions,200*removals' build-essential clang-6.0 libstdc++-7-dev git libboost-all-dev python-pip libssl-dev`
- `sudo pip install cmake`
- `export CC=clang-6.0`
- `export CXX=clang++-6.0`
- `git clone https://github.com/catalystdevelopment/catalyst`
- `cd catalyst`
- `mkdir build`
- `cd build`
- `cmake ..`
- `make`

The binaries will be in the `src` folder when you are complete.

- `cd src`
- `./Catalystd --version`

##### Generic Linux

Ensure you have the dependencies listed above.

If you want to use clang, ensure you set the environment variables `CC` and `CXX`.
See the ubuntu instructions for an example.

- `git clone https://github.com/catalystdevelopment/catalyst`
- `cd catalyst`
- `mkdir build`
- `cd build`
- `cmake ..`
- `make`

The binaries will be in the `src` folder when you are complete.

- `cd src`
- `./Catalystd --version`

#### OSX/Apple, using GCC

##### Prerequisites

- Install XCode and Developer Tools.

##### Building

- `which brew || /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"`
- `brew install --force cmake boost llvm gcc@8 openssl`
- `export CC=gcc-8`
- `export CXX=g++-8`
- `git clone https://github.com/catalystdevelopment/catalyst`
- `cd catalyst`
- `mkdir build`
- `cd build`
- `cmake ..`
- `make`

The binaries will be in the `src` folder when you are complete.

- `cd src`
- `./Catalystd --version`

#### OSX/Apple, using Clang

##### Prerequisites

- Install XCode and Developer Tools.

##### Building

- `which brew || /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"`
- `brew install --force cmake boost llvm openssl`
- `export CC=/usr/local/opt/llvm/bin/clang`
- `export CXX=/usr/local/opt/llvm/bin/clang++`
- `git clone https://github.com/catalystdevelopment/catalyst`
- `cd catalyst`
- `mkdir build`
- `cd build`
- `cmake ..`
- `make`

The binaries will be in the `src` folder when you are complete.

- `cd src`
- `./Catalystd --version`


#### Windows

##### Prerequisites

You can build for 32-bit or 64-bit Windows. **If you're not sure, pick 64-bit.**

- Install [Visual Studio 2017 Community Edition](https://www.visualstudio.com/thank-you-downloading-visual-studio/?sku=Community&rel=15&page=inlineinstall)
- When installing Visual Studio, it is **required** that you install **Desktop development with C++**
- Install the latest version of Boost (currently Boost 1.68). Select the appropriate version for your system:
  - [Boost 64-bit](https://bintray.com/boostorg/release/download_file?file_path=1.68.0%2Fbinaries%2Fboost_1_68_0-msvc-14.1-64.exe)
  - [Boost 32-bit](https://bintray.com/boostorg/release/download_file?file_path=1.68.0%2Fbinaries%2Fboost_1_68_0-msvc-14.1-32.exe)
- Install the latest full version of OpenSSL (currently OpenSSL 1.1.1b). Select the appropriate version for your system:
  - [OpenSSL 64-bit](https://slproweb.com/download/Win64OpenSSL-1_1_1b.exe)
  - [OpenSSL 32-bit](https://slproweb.com/download/Win32OpenSSL-1_1_1b.exe)

##### Building

For 64-bit:
- From the start menu, open 'x64 Native Tools Command Prompt for vs2017'.
- `cd <your_catalyst_directory>`
- `mkdir build`
- `cd build`
- `set PATH="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin";%PATH%`
- `cmake -G "Visual Studio 15 2017 Win64" .. -DBOOST_ROOT=C:/local/boost_1_68_0`

If you have errors on this step about not being able to find the following static libraries, you may need to update your cmake. Open 'Visual Studio Installer' and click 'Update'.

- `MSBuild Catalyst.sln /p:Configuration=Release /m`

For 32-bit:
- From the start menu, open 'x86 Native Tools Command Prompt for vs2017'.
- `cd <your_catalyst_directory>`
- `mkdir build`
- `cd build`
- `set PATH="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin";%PATH%`
- `cmake -G "Visual Studio 15 2017" .. -DBOOST_ROOT=C:/local/boost_1_68_0`
- `MSBuild Catalyst.sln /p:Configuration=Release /p:Platform=Win32 /m`

The binaries will be in the `src/Release` folder when you are complete.

- `cd src`
- `cd Release`
- `Catalystd.exe --version`

#### Thanks
Cryptonote Developers, Bytecoin Developers, Monero Developers, Forknote Project, TurtleCoin Community

### Copypasta for license when editing files
<!--
Hi Catalyst contributor, thanks for forking and sending back Pull Requests. Extensive docs about contributing are in the works or elsewhere. For now this is the bit we need to get into all the files we touch. Please add it to the top of the files, see [src/CryptoNoteConfig.h](https://github.com/turtlecoin/turtlecoin/commit/28cfef2575f2d767f6e512f2a4017adbf44e610e) for an example.
-->

```
// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2014-2018, The Monero Project
// Copyright (c) 2018-2019, The TurtleCoin Developers
// Copyright (c) 2018-2019, The Catalyst Developers
// 
// Please see the included LICENSE file for more information.
```
