# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/water/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.6015.37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/water/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.6015.37/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/water/blockchains/catalyst-cli

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/water/blockchains/catalyst-cli/cmake-build-debug

# Utility rule file for pool.

# Include the progress variables for this target.
include src/CMakeFiles/pool.dir/progress.make

src/CMakeFiles/pool: src/Catalystd
src/CMakeFiles/pool: ../src/service


pool: src/CMakeFiles/pool
pool: src/CMakeFiles/pool.dir/build.make

.PHONY : pool

# Rule to build all files generated by this target.
src/CMakeFiles/pool.dir/build: pool

.PHONY : src/CMakeFiles/pool.dir/build

src/CMakeFiles/pool.dir/clean:
	cd /home/water/blockchains/catalyst-cli/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/pool.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/pool.dir/clean

src/CMakeFiles/pool.dir/depend:
	cd /home/water/blockchains/catalyst-cli/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/water/blockchains/catalyst-cli /home/water/blockchains/catalyst-cli/src /home/water/blockchains/catalyst-cli/cmake-build-debug /home/water/blockchains/catalyst-cli/cmake-build-debug/src /home/water/blockchains/catalyst-cli/cmake-build-debug/src/CMakeFiles/pool.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/pool.dir/depend

