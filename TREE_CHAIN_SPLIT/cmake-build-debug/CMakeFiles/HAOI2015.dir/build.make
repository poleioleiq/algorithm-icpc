# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\algorihtm\TREE_CHAIN_SPLIT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\algorihtm\TREE_CHAIN_SPLIT\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HAOI2015.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HAOI2015.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HAOI2015.dir/flags.make

CMakeFiles/HAOI2015.dir/HAOI2015.cpp.obj: CMakeFiles/HAOI2015.dir/flags.make
CMakeFiles/HAOI2015.dir/HAOI2015.cpp.obj: ../HAOI2015.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\algorihtm\TREE_CHAIN_SPLIT\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HAOI2015.dir/HAOI2015.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\HAOI2015.dir\HAOI2015.cpp.obj -c E:\algorihtm\TREE_CHAIN_SPLIT\HAOI2015.cpp

CMakeFiles/HAOI2015.dir/HAOI2015.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HAOI2015.dir/HAOI2015.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\algorihtm\TREE_CHAIN_SPLIT\HAOI2015.cpp > CMakeFiles\HAOI2015.dir\HAOI2015.cpp.i

CMakeFiles/HAOI2015.dir/HAOI2015.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HAOI2015.dir/HAOI2015.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\algorihtm\TREE_CHAIN_SPLIT\HAOI2015.cpp -o CMakeFiles\HAOI2015.dir\HAOI2015.cpp.s

# Object files for target HAOI2015
HAOI2015_OBJECTS = \
"CMakeFiles/HAOI2015.dir/HAOI2015.cpp.obj"

# External object files for target HAOI2015
HAOI2015_EXTERNAL_OBJECTS =

HAOI2015.exe: CMakeFiles/HAOI2015.dir/HAOI2015.cpp.obj
HAOI2015.exe: CMakeFiles/HAOI2015.dir/build.make
HAOI2015.exe: CMakeFiles/HAOI2015.dir/linklibs.rsp
HAOI2015.exe: CMakeFiles/HAOI2015.dir/objects1.rsp
HAOI2015.exe: CMakeFiles/HAOI2015.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\algorihtm\TREE_CHAIN_SPLIT\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HAOI2015.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\HAOI2015.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HAOI2015.dir/build: HAOI2015.exe

.PHONY : CMakeFiles/HAOI2015.dir/build

CMakeFiles/HAOI2015.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HAOI2015.dir\cmake_clean.cmake
.PHONY : CMakeFiles/HAOI2015.dir/clean

CMakeFiles/HAOI2015.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\algorihtm\TREE_CHAIN_SPLIT E:\algorihtm\TREE_CHAIN_SPLIT E:\algorihtm\TREE_CHAIN_SPLIT\cmake-build-debug E:\algorihtm\TREE_CHAIN_SPLIT\cmake-build-debug E:\algorihtm\TREE_CHAIN_SPLIT\cmake-build-debug\CMakeFiles\HAOI2015.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HAOI2015.dir/depend

