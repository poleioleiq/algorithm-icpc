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
include CMakeFiles/HDU_3462.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HDU_3462.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HDU_3462.dir/flags.make

CMakeFiles/HDU_3462.dir/HDU_3462.cpp.obj: CMakeFiles/HDU_3462.dir/flags.make
CMakeFiles/HDU_3462.dir/HDU_3462.cpp.obj: ../HDU_3462.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\algorihtm\SEGMENT\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HDU_3462.dir/HDU_3462.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\HDU_3462.dir\HDU_3462.cpp.obj -c E:\algorihtm\SEGMENT\HDU_3462.cpp

CMakeFiles/HDU_3462.dir/HDU_3462.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HDU_3462.dir/HDU_3462.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\algorihtm\SEGMENT\HDU_3462.cpp > CMakeFiles\HDU_3462.dir\HDU_3462.cpp.i

CMakeFiles/HDU_3462.dir/HDU_3462.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HDU_3462.dir/HDU_3462.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\algorihtm\SEGMENT\HDU_3462.cpp -o CMakeFiles\HDU_3462.dir\HDU_3462.cpp.s

# Object files for target HDU_3462
HDU_3462_OBJECTS = \
"CMakeFiles/HDU_3462.dir/HDU_3462.cpp.obj"

# External object files for target HDU_3462
HDU_3462_EXTERNAL_OBJECTS =

HDU_3462.exe: CMakeFiles/HDU_3462.dir/HDU_3462.cpp.obj
HDU_3462.exe: CMakeFiles/HDU_3462.dir/build.make
HDU_3462.exe: CMakeFiles/HDU_3462.dir/linklibs.rsp
HDU_3462.exe: CMakeFiles/HDU_3462.dir/objects1.rsp
HDU_3462.exe: CMakeFiles/HDU_3462.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\algorihtm\SEGMENT\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HDU_3462.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\HDU_3462.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HDU_3462.dir/build: HDU_3462.exe

.PHONY : CMakeFiles/HDU_3462.dir/build

CMakeFiles/HDU_3462.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HDU_3462.dir\cmake_clean.cmake
.PHONY : CMakeFiles/HDU_3462.dir/clean

CMakeFiles/HDU_3462.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\algorihtm\SEGMENT E:\algorihtm\SEGMENT E:\algorihtm\SEGMENT\cmake-build-debug E:\algorihtm\SEGMENT\cmake-build-debug E:\algorihtm\SEGMENT\cmake-build-debug\CMakeFiles\HDU_3462.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HDU_3462.dir/depend

