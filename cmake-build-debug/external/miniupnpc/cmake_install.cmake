# Install script for directory: /home/water/blockchains/catalyst-cli/external/miniupnpc

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/miniupnpc" TYPE FILE FILES
    "/home/water/blockchains/catalyst-cli/external/miniupnpc/miniupnpc.h"
    "/home/water/blockchains/catalyst-cli/external/miniupnpc/miniwget.h"
    "/home/water/blockchains/catalyst-cli/external/miniupnpc/upnpcommands.h"
    "/home/water/blockchains/catalyst-cli/external/miniupnpc/igd_desc_parse.h"
    "/home/water/blockchains/catalyst-cli/external/miniupnpc/upnpreplyparse.h"
    "/home/water/blockchains/catalyst-cli/external/miniupnpc/upnperrors.h"
    "/home/water/blockchains/catalyst-cli/external/miniupnpc/upnpdev.h"
    "/home/water/blockchains/catalyst-cli/external/miniupnpc/miniupnpctypes.h"
    "/home/water/blockchains/catalyst-cli/external/miniupnpc/portlistingparse.h"
    "/home/water/blockchains/catalyst-cli/external/miniupnpc/miniupnpc_declspec.h"
    )
endif()

