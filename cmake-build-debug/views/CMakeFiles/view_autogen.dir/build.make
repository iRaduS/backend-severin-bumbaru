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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/raduvrinceanu/Desktop/backend

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/raduvrinceanu/Desktop/backend/cmake-build-debug

# Utility rule file for view_autogen.

# Include the progress variables for this target.
include views/CMakeFiles/view_autogen.dir/progress.make

views/CMakeFiles/view_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/raduvrinceanu/Desktop/backend/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target view"
	cd /Users/raduvrinceanu/Desktop/backend/cmake-build-debug/views && /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E cmake_autogen /Users/raduvrinceanu/Desktop/backend/cmake-build-debug/views/CMakeFiles/view_autogen.dir/AutogenInfo.json Debug

view_autogen: views/CMakeFiles/view_autogen
view_autogen: views/CMakeFiles/view_autogen.dir/build.make

.PHONY : view_autogen

# Rule to build all files generated by this target.
views/CMakeFiles/view_autogen.dir/build: view_autogen

.PHONY : views/CMakeFiles/view_autogen.dir/build

views/CMakeFiles/view_autogen.dir/clean:
	cd /Users/raduvrinceanu/Desktop/backend/cmake-build-debug/views && $(CMAKE_COMMAND) -P CMakeFiles/view_autogen.dir/cmake_clean.cmake
.PHONY : views/CMakeFiles/view_autogen.dir/clean

views/CMakeFiles/view_autogen.dir/depend:
	cd /Users/raduvrinceanu/Desktop/backend/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/raduvrinceanu/Desktop/backend /Users/raduvrinceanu/Desktop/backend/views /Users/raduvrinceanu/Desktop/backend/cmake-build-debug /Users/raduvrinceanu/Desktop/backend/cmake-build-debug/views /Users/raduvrinceanu/Desktop/backend/cmake-build-debug/views/CMakeFiles/view_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : views/CMakeFiles/view_autogen.dir/depend

