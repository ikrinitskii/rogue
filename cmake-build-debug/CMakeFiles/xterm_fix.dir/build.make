# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /snap/clion/139/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/139/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ik/rogue

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ik/rogue/cmake-build-debug

# Utility rule file for xterm_fix.

# Include the progress variables for this target.
include CMakeFiles/xterm_fix.dir/progress.make

CMakeFiles/xterm_fix:
	export TERM=xterm

xterm_fix: CMakeFiles/xterm_fix
xterm_fix: CMakeFiles/xterm_fix.dir/build.make

.PHONY : xterm_fix

# Rule to build all files generated by this target.
CMakeFiles/xterm_fix.dir/build: xterm_fix

.PHONY : CMakeFiles/xterm_fix.dir/build

CMakeFiles/xterm_fix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/xterm_fix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/xterm_fix.dir/clean

CMakeFiles/xterm_fix.dir/depend:
	cd /home/ik/rogue/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ik/rogue /home/ik/rogue /home/ik/rogue/cmake-build-debug /home/ik/rogue/cmake-build-debug /home/ik/rogue/cmake-build-debug/CMakeFiles/xterm_fix.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/xterm_fix.dir/depend

