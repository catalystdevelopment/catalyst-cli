// Copyright (c) 2018, The TurtleCoin Developers
// Copyright (c) 2018, The Catalyst Developers
//
// Please see the included LICENSE file for more information

#pragma once

const std::string windowsAsciiArt =
      "\n
      "_________         __         .__                  __   \n"
      "\_   ___ \_____ _/  |______  |  | ___.__. _______/  |_ \n"
      "/    \  \/\__  \\   __\__  \ |  |<   |  |/  ___/\   __\\n"
      "\     \____/ __ \|  |  / __ \|  |_\___  |\___ \  |  |  \n"
      " \______  (____  /__| (____  /____/ ____/____  > |__|  \n"
      "        \/     \/          \/     \/         \/        \n";


const std::string nonWindowsAsciiArt =
      "\n
      "_________         __         .__                  __   \n"
      "\_   ___ \_____ _/  |______  |  | ___.__. _______/  |_ \n"
      "/    \  \/\__  \\   __\__  \ |  |<   |  |/  ___/\   __\\n"
      "\     \____/ __ \|  |  / __ \|  |_\___  |\___ \  |  |  \n"
      " \______  (____  /__| (____  /____/ ____/____  > |__|  \n"
      "        \/     \/          \/     \/         \/        \n";

/* Windows has some characters it won't display in a terminal. If your ascii
   art works fine on Windows and Linux terminals, just replace 'asciiArt' with
   the art itself, and remove these two #ifdefs and above ascii arts */
#ifdef _WIN32
const std::string asciiArt = windowsAsciiArt;
#else
const std::string asciiArt = nonWindowsAsciiArt;
#endif
