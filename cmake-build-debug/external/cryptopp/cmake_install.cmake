# Install script for directory: /home/water/blockchains/catalyst-cli/external/cryptopp

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64" TYPE STATIC_LIBRARY FILES "/home/water/blockchains/catalyst-cli/cmake-build-debug/external/cryptopp/libcryptopp.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cryptopp" TYPE FILE FILES
    "/home/water/blockchains/catalyst-cli/external/cryptopp/3way.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/adler32.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/adv_simd.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/aes.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/aes_armv4.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/algebra.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/algparam.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/arc4.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/argnames.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/aria.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/arm_simd.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/asn.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/authenc.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/base32.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/base64.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/basecode.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/blake2.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/blowfish.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/blumshub.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/camellia.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/cast.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/cbcmac.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/ccm.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/chacha.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/chachapoly.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/cham.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/channels.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/cmac.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/config.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/cpu.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/crc.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/cryptlib.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/darn.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/default.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/des.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/dh.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/dh2.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/dll.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/dmac.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/donna.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/donna_32.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/donna_64.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/donna_sse.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/drbg.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/dsa.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/eax.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/ec2n.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/eccrypto.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/ecp.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/ecpoint.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/elgamal.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/emsa2.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/eprecomp.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/esign.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/factory.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/fhmqv.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/files.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/filters.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/fips140.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/fltrimpl.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/gcm.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/gf256.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/gf2_32.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/gf2n.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/gfpcrypt.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/gost.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/gzip.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/hashfwd.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/hc128.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/hc256.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/hex.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/hight.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/hkdf.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/hmac.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/hmqv.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/hrtimer.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/ida.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/idea.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/integer.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/iterhash.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/kalyna.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/keccak.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/lea.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/lubyrack.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/luc.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/mars.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/md2.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/md4.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/md5.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/mdc.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/mersenne.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/misc.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/modarith.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/modes.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/modexppc.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/mqueue.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/mqv.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/naclite.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/nbtheory.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/nr.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/oaep.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/oids.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/osrng.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/ossig.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/padlkrng.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/panama.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/pch.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/pkcspad.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/poly1305.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/polynomi.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/ppc_simd.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/pssr.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/pubkey.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/pwdbased.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/queue.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/rabbit.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/rabin.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/randpool.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/rc2.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/rc5.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/rc6.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/rdrand.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/resource.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/rijndael.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/ripemd.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/rng.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/rsa.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/rw.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/safer.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/salsa.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/scrypt.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/seal.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/secblock.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/seckey.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/seed.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/serpent.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/serpentp.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/sha.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/sha3.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/shacal2.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/shake.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/shark.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/simeck.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/simon.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/simple.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/siphash.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/skipjack.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/sm3.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/sm4.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/smartptr.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/sosemanuk.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/speck.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/square.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/stdcpp.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/strciphr.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/tea.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/threefish.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/tiger.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/trap.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/trunhash.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/ttmac.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/tweetnacl.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/twofish.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/vmac.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/wake.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/whrlpool.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/words.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/xed25519.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/xtr.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/xtrcrypt.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/zdeflate.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/zinflate.h"
    "/home/water/blockchains/catalyst-cli/external/cryptopp/zlib.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/cryptopp" TYPE FILE FILES
    "/home/water/blockchains/catalyst-cli/external/cryptopp/cryptopp-config.cmake"
    "/home/water/blockchains/catalyst-cli/cmake-build-debug/external/cryptopp/cryptopp-config-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/cryptopp/cryptopp-targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/cryptopp/cryptopp-targets.cmake"
         "/home/water/blockchains/catalyst-cli/cmake-build-debug/external/cryptopp/CMakeFiles/Export/lib/cmake/cryptopp/cryptopp-targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/cryptopp/cryptopp-targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/cryptopp/cryptopp-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/cryptopp" TYPE FILE FILES "/home/water/blockchains/catalyst-cli/cmake-build-debug/external/cryptopp/CMakeFiles/Export/lib/cmake/cryptopp/cryptopp-targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/cryptopp" TYPE FILE FILES "/home/water/blockchains/catalyst-cli/cmake-build-debug/external/cryptopp/CMakeFiles/Export/lib/cmake/cryptopp/cryptopp-targets-debug.cmake")
  endif()
endif()

