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
include CMakeFiles/BZOJ_4337.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BZOJ_4337.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BZOJ_4337.dir/flags.make

CMakeFiles/BZOJ_4337.dir/Merkle_Tree/BZOJ_4337.cpp.obj: CMakeFiles/BZOJ_4337.dir/flags.make
CMakeFiles/BZOJ_4337.dir/Merkle_Tree/BZOJ_4337.cpp.obj: ../Merkle_Tree/BZOJ_4337.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\algorihtm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BZOJ_4337.dir/Merkle_Tree/BZOJ_4337.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BZOJ_4337.dir\Merkle_Tree\BZOJ_4337.cpp.obj -c E:\algorihtm\Merkle_Tree\BZOJ_4337.cpp

CMakeFiles/BZOJ_4337.dir/Merkle_Tree/BZOJ_4337.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BZOJ_4337.dir/Merkle_Tree/BZOJ_4337.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\algorihtm\Merkle_Tree\BZOJ_4337.cpp > CMakeFiles\BZOJ_4337.dir\Merkle_Tree\BZOJ_4337.cpp.i

CMakeFiles/BZOJ_4337.dir/Merkle_Tree/BZOJ_4337.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BZOJ_4337.dir/Merkle_Tree/BZOJ_4337.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\algorihtm\Merkle_Tree\BZOJ_4337.cpp -o CMakeFiles\BZOJ_4337.dir\Merkle_Tree\BZOJ_4337.cpp.s

# Object files for target BZOJ_4337
BZOJ_4337_OBJECTS = \
"CMakeFiles/BZOJ_4337.dir/Merkle_Tree/BZOJ_4337.cpp.obj"

# External object files for target BZOJ_4337
BZOJ_4337_EXTERNAL_OBJECTS =

BZOJ_4337.exe: CMakeFiles/BZOJ_4337.dir/Merkle_Tree/BZOJ_4337.cpp.obj
BZOJ_4337.exe: CMakeFiles/BZOJ_4337.dir/build.make
BZOJ_4337.exe: CMakeFiles/BZOJ_4337.dir/linklibs.rsp
BZOJ_4337.exe: CMakeFiles/BZOJ_4337.dir/objects1.rsp
BZOJ_4337.exe: CMakeFiles/BZOJ_4337.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\algorihtm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BZOJ_4337.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BZOJ_4337.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BZOJ_4337.dir/build: BZOJ_4337.exe

.PHONY : CMakeFiles/BZOJ_4337.dir/build

CMakeFiles/BZOJ_4337.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BZOJ_4337.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BZOJ_4337.dir/clean

CMakeFiles/BZOJ_4337.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\algorihtm E:\algorihtm E:\algorihtm\cmake-build-debug E:\algorihtm\cmake-build-debug E:\algorihtm\cmake-build-debug\CMakeFiles\BZOJ_4337.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BZOJ_4337.dir/depend
