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
CMAKE_SOURCE_DIR = E:\algorihtm\SEGMENT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\algorihtm\SEGMENT\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/POJ_2528.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/POJ_2528.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/POJ_2528.dir/flags.make

CMakeFiles/POJ_2528.dir/POJ_2528.cpp.obj: CMakeFiles/POJ_2528.dir/flags.make
CMakeFiles/POJ_2528.dir/POJ_2528.cpp.obj: ../POJ_2528.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\algorihtm\SEGMENT\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/POJ_2528.dir/POJ_2528.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\POJ_2528.dir\POJ_2528.cpp.obj -c E:\algorihtm\SEGMENT\POJ_2528.cpp

CMakeFiles/POJ_2528.dir/POJ_2528.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/POJ_2528.dir/POJ_2528.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\algorihtm\SEGMENT\POJ_2528.cpp > CMakeFiles\POJ_2528.dir\POJ_2528.cpp.i

CMakeFiles/POJ_2528.dir/POJ_2528.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/POJ_2528.dir/POJ_2528.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\algorihtm\SEGMENT\POJ_2528.cpp -o CMakeFiles\POJ_2528.dir\POJ_2528.cpp.s

# Object files for target POJ_2528
POJ_2528_OBJECTS = \
"CMakeFiles/POJ_2528.dir/POJ_2528.cpp.obj"

# External object files for target POJ_2528
POJ_2528_EXTERNAL_OBJECTS =

POJ_2528.exe: CMakeFiles/POJ_2528.dir/POJ_2528.cpp.obj
POJ_2528.exe: CMakeFiles/POJ_2528.dir/build.make
POJ_2528.exe: CMakeFiles/POJ_2528.dir/linklibs.rsp
POJ_2528.exe: CMakeFiles/POJ_2528.dir/objects1.rsp
POJ_2528.exe: CMakeFiles/POJ_2528.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\algorihtm\SEGMENT\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable POJ_2528.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\POJ_2528.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/POJ_2528.dir/build: POJ_2528.exe

.PHONY : CMakeFiles/POJ_2528.dir/build

CMakeFiles/POJ_2528.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\POJ_2528.dir\cmake_clean.cmake
.PHONY : CMakeFiles/POJ_2528.dir/clean

CMakeFiles/POJ_2528.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\algorihtm\SEGMENT E:\algorihtm\SEGMENT E:\algorihtm\SEGMENT\cmake-build-debug E:\algorihtm\SEGMENT\cmake-build-debug E:\algorihtm\SEGMENT\cmake-build-debug\CMakeFiles\POJ_2528.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/POJ_2528.dir/depend

