// Copyright (c) 2018, The TurtleCoin Developers
// Copyright (c) 2018, The Catalyst Developers
//
// Please see the included LICENSE file for more information

#pragma once

//  New logo, replace old logo because of warnings
//    ______      __        __           __ 
//   / ____/___ _/ /_____ _/ /_  _______/ /_
//  / /   / __ `/ __/ __ `/ / / / / ___/ __/
// / /___/ /_/ / /_/ /_/ / / /_/ (__  ) /_  
// \____/\__,_/\__/\__,_/_/\__, /____/\__/  
//                        /____/            


const std::string windowsAsciiArt =
      "\n                                       \n"
      "   ______      __        __           __ \n"
      "  / ____/___ _/ /_____ _/ /_  _______/ /_\n"
      " / /   / __ `/ __/ __ `/ / / / / ___/ __/\n"
      "/ /___/ /_/ / /_/ /_/ / / /_/ (__  ) /_  \n"
      "\____/\__,_/\__/\__,_/_/\__, /____/\__/  \n"
      "                       /____/            \n";


const std::string nonWindowsAsciiArt =
      "\n                                       \n"
      "   ______      __        __           __ \n"
      "  / ____/___ _/ /_____ _/ /_  _______/ /_\n"
      " / /   / __ `/ __/ __ `/ / / / / ___/ __/\n"
      "/ /___/ /_/ / /_/ /_/ / / /_/ (__  ) /_  \n"
      "\____/\__,_/\__/\__,_/_/\__, /____/\__/  \n"
      "                       /____/            \n";

/* Windows has some characters it won't display in a terminal. If your ascii
   art works fine on Windows and Linux terminals, just replace 'asciiArt' with
   the art itself, and remove these two #ifdefs and above ascii arts */
#ifdef _WIN32
const std::string asciiArt = windowsAsciiArt;
#else
const std::string asciiArt = nonWindowsAsciiArt;
#endif
