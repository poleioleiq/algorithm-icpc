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
CMAKE_SOURCE_DIR = E:\algorihtm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\algorihtm\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2.dir/flags.make

CMakeFiles/2.dir/Home_Work/8.cpp.obj: CMakeFiles/2.dir/flags.make
CMakeFiles/2.dir/Home_Work/8.cpp.obj: ../Home_Work/8.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\algorihtm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2.dir/Home_Work/8.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2.dir\Home_Work\8.cpp.obj -c E:\algorihtm\Home_Work\8.cpp

CMakeFiles/2.dir/Home_Work/8.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2.dir/Home_Work/8.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\algorihtm\Home_Work\8.cpp > CMakeFiles\2.dir\Home_Work\8.cpp.i

CMakeFiles/2.dir/Home_Work/8.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2.dir/Home_Work/8.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\algorihtm\Home_Work\8.cpp -o CMakeFiles\2.dir\Home_Work\8.cpp.s

# Object files for target 2
2_OBJECTS = \
"CMakeFiles/2.dir/Home_Work/8.cpp.obj"

# External object files for target 2
2_EXTERNAL_OBJECTS =

2.exe: CMakeFiles/2.dir/Home_Work/8.cpp.obj
2.exe: CMakeFiles/2.dir/build.make
2.exe: CMakeFiles/2.dir/linklibs.rsp
2.exe: CMakeFiles/2.dir/objects1.rsp
2.exe: CMakeFiles/2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\algorihtm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2.dir/build: 2.exe

.PHONY : CMakeFiles/2.dir/build

CMakeFiles/2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/2.dir/clean

CMakeFiles/2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\algorihtm E:\algorihtm E:\algorihtm\cmake-build-debug E:\algorihtm\cmake-build-debug E:\algorihtm\cmake-build-debug\CMakeFiles\2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2.dir/depend

