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
include CMakeFiles/BZ.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BZ.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BZ.dir/flags.make

CMakeFiles/BZ.dir/K_D_Tree/BZOJ_4520.cpp.obj: CMakeFiles/BZ.dir/flags.make
CMakeFiles/BZ.dir/K_D_Tree/BZOJ_4520.cpp.obj: ../K_D_Tree/BZOJ_4520.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\algorihtm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BZ.dir/K_D_Tree/BZOJ_4520.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BZ.dir\K_D_Tree\BZOJ_4520.cpp.obj -c E:\algorihtm\K_D_Tree\BZOJ_4520.cpp

CMakeFiles/BZ.dir/K_D_Tree/BZOJ_4520.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BZ.dir/K_D_Tree/BZOJ_4520.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\algorihtm\K_D_Tree\BZOJ_4520.cpp > CMakeFiles\BZ.dir\K_D_Tree\BZOJ_4520.cpp.i

CMakeFiles/BZ.dir/K_D_Tree/BZOJ_4520.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BZ.dir/K_D_Tree/BZOJ_4520.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\algorihtm\K_D_Tree\BZOJ_4520.cpp -o CMakeFiles\BZ.dir\K_D_Tree\BZOJ_4520.cpp.s

# Object files for target BZ
BZ_OBJECTS = \
"CMakeFiles/BZ.dir/K_D_Tree/BZOJ_4520.cpp.obj"

# External object files for target BZ
BZ_EXTERNAL_OBJECTS =

BZ.exe: CMakeFiles/BZ.dir/K_D_Tree/BZOJ_4520.cpp.obj
BZ.exe: CMakeFiles/BZ.dir/build.make
BZ.exe: CMakeFiles/BZ.dir/linklibs.rsp
BZ.exe: CMakeFiles/BZ.dir/objects1.rsp
BZ.exe: CMakeFiles/BZ.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\algorihtm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BZ.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BZ.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BZ.dir/build: BZ.exe

.PHONY : CMakeFiles/BZ.dir/build

CMakeFiles/BZ.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BZ.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BZ.dir/clean

CMakeFiles/BZ.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\algorihtm E:\algorihtm E:\algorihtm\cmake-build-debug E:\algorihtm\cmake-build-debug E:\algorihtm\cmake-build-debug\CMakeFiles\BZ.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BZ.dir/depend

