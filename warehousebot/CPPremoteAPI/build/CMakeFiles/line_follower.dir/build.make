# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\victo\Git\engsoft\line_follower\CPPremoteAPI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\victo\Git\engsoft\line_follower\CPPremoteAPI\build

# Include any dependencies generated for this target.
include CMakeFiles/line_follower.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/line_follower.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/line_follower.dir/flags.make

CMakeFiles/line_follower.dir/main.cpp.obj: CMakeFiles/line_follower.dir/flags.make
CMakeFiles/line_follower.dir/main.cpp.obj: CMakeFiles/line_follower.dir/includes_CXX.rsp
CMakeFiles/line_follower.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Git\engsoft\line_follower\CPPremoteAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/line_follower.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\line_follower.dir\main.cpp.obj -c C:\Users\victo\Git\engsoft\line_follower\CPPremoteAPI\main.cpp

CMakeFiles/line_follower.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/line_follower.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\victo\Git\engsoft\line_follower\CPPremoteAPI\main.cpp > CMakeFiles\line_follower.dir\main.cpp.i

CMakeFiles/line_follower.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/line_follower.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\victo\Git\engsoft\line_follower\CPPremoteAPI\main.cpp -o CMakeFiles\line_follower.dir\main.cpp.s

CMakeFiles/line_follower.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/line_follower.dir/main.cpp.obj.requires

CMakeFiles/line_follower.dir/main.cpp.obj.provides: CMakeFiles/line_follower.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\line_follower.dir\build.make CMakeFiles/line_follower.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/line_follower.dir/main.cpp.obj.provides

CMakeFiles/line_follower.dir/main.cpp.obj.provides.build: CMakeFiles/line_follower.dir/main.cpp.obj


CMakeFiles/line_follower.dir/remoteApi/extApi.c.obj: CMakeFiles/line_follower.dir/flags.make
CMakeFiles/line_follower.dir/remoteApi/extApi.c.obj: CMakeFiles/line_follower.dir/includes_C.rsp
CMakeFiles/line_follower.dir/remoteApi/extApi.c.obj: ../remoteApi/extApi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Git\engsoft\line_follower\CPPremoteAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/line_follower.dir/remoteApi/extApi.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\line_follower.dir\remoteApi\extApi.c.obj   -c C:\Users\victo\Git\engsoft\line_follower\CPPremoteAPI\remoteApi\extApi.c

CMakeFiles/line_follower.dir/remoteApi/extApi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/line_follower.dir/remoteApi/extApi.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\victo\Git\engsoft\line_follower\CPPremoteAPI\remoteApi\extApi.c > CMakeFiles\line_follower.dir\remoteApi\extApi.c.i

CMakeFiles/line_follower.dir/remoteApi/extApi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/line_follower.dir/remoteApi/extApi.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\victo\Git\engsoft\line_follower\CPPremoteAPI\remoteApi\extApi.c -o CMakeFiles\line_follower.dir\remoteApi\extApi.c.s

CMakeFiles/line_follower.dir/remoteApi/extApi.c.obj.requires:

.PHONY : CMakeFiles/line_follower.dir/remoteApi/extApi.c.obj.requires

CMakeFiles/line_follower.dir/remoteApi/extApi.c.obj.provides: CMakeFiles/line_follower.dir/remoteApi/extApi.c.obj.requires
	$(MAKE) -f CMakeFiles\line_follower.dir\build.make CMakeFiles/line_follower.dir/remoteApi/extApi.c.obj.provides.build
.PHONY : CMakeFiles/line_follower.dir/remoteApi/extApi.c.obj.provides

CMakeFiles/line_follower.dir/remoteApi/extApi.c.obj.provides.build: CMakeFiles/line_follower.dir/remoteApi/extApi.c.obj


CMakeFiles/line_follower.dir/remoteApi/extApiPlatform.c.obj: CMakeFiles/line_follower.dir/flags.make
CMakeFiles/line_follower.dir/remoteApi/extApiPlatform.c.obj: CMakeFiles/line_follower.dir/includes_C.rsp
CMakeFiles/line_follower.dir/remoteApi/extApiPlatform.c.obj: ../remoteApi/extApiPlatform.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Git\engsoft\line_follower\CPPremoteAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/line_follower.dir/remoteApi/extApiPlatform.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\line_follower.dir\remoteApi\extApiPlatform.c.obj   -c C:\Users\victo\Git\engsoft\line_follower\CPPremoteAPI\remoteApi\extApiPlatform.c

CMakeFiles/line_follower.dir/remoteApi/extApiPlatform.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/line_follower.dir/remoteApi/extApiPlatform.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\victo\Git\engsoft\line_follower\CPPremoteAPI\remoteApi\extApiPlatform.c > CMakeFiles\line_follower.dir\remoteApi\extApiPlatform.c.i

CMakeFiles/line_follower.dir/remoteApi/extApiPlatform.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/line_follower.dir/remoteApi/extApiPlatform.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\victo\Git\engsoft\line_follower\CPPremoteAPI\remoteApi\extApiPlatform.c -o CMakeFiles\line_follower.dir\remoteApi\extApiPlatform.c.s

CMakeFiles/line_follower.dir/remoteApi/extApiPlatform.c.obj.requires:

.PHONY : CMakeFiles/line_follower.dir/remoteApi/extApiPlatform.c.obj.requires

CMakeFiles/line_follower.dir/remoteApi/extApiPlatform.c.obj.provides: CMakeFiles/line_follower.dir/remoteApi/extApiPlatform.c.obj.requires
	$(MAKE) -f CMakeFiles\line_follower.dir\build.make CMakeFiles/line_follower.dir/remoteApi/extApiPlatform.c.obj.provides.build
.PHONY : CMakeFiles/line_follower.dir/remoteApi/extApiPlatform.c.obj.provides

CMakeFiles/line_follower.dir/remoteApi/extApiPlatform.c.obj.provides.build: CMakeFiles/line_follower.dir/remoteApi/extApiPlatform.c.obj


# Object files for target line_follower
line_follower_OBJECTS = \
"CMakeFiles/line_follower.dir/main.cpp.obj" \
"CMakeFiles/line_follower.dir/remoteApi/extApi.c.obj" \
"CMakeFiles/line_follower.dir/remoteApi/extApiPlatform.c.obj"

# External object files for target line_follower
line_follower_EXTERNAL_OBJECTS =

line_follower.exe: CMakeFiles/line_follower.dir/main.cpp.obj
line_follower.exe: CMakeFiles/line_follower.dir/remoteApi/extApi.c.obj
line_follower.exe: CMakeFiles/line_follower.dir/remoteApi/extApiPlatform.c.obj
line_follower.exe: CMakeFiles/line_follower.dir/build.make
line_follower.exe: CMakeFiles/line_follower.dir/linklibs.rsp
line_follower.exe: CMakeFiles/line_follower.dir/objects1.rsp
line_follower.exe: CMakeFiles/line_follower.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\victo\Git\engsoft\line_follower\CPPremoteAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable line_follower.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\line_follower.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/line_follower.dir/build: line_follower.exe

.PHONY : CMakeFiles/line_follower.dir/build

CMakeFiles/line_follower.dir/requires: CMakeFiles/line_follower.dir/main.cpp.obj.requires
CMakeFiles/line_follower.dir/requires: CMakeFiles/line_follower.dir/remoteApi/extApi.c.obj.requires
CMakeFiles/line_follower.dir/requires: CMakeFiles/line_follower.dir/remoteApi/extApiPlatform.c.obj.requires

.PHONY : CMakeFiles/line_follower.dir/requires

CMakeFiles/line_follower.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\line_follower.dir\cmake_clean.cmake
.PHONY : CMakeFiles/line_follower.dir/clean

CMakeFiles/line_follower.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\victo\Git\engsoft\line_follower\CPPremoteAPI C:\Users\victo\Git\engsoft\line_follower\CPPremoteAPI C:\Users\victo\Git\engsoft\line_follower\CPPremoteAPI\build C:\Users\victo\Git\engsoft\line_follower\CPPremoteAPI\build C:\Users\victo\Git\engsoft\line_follower\CPPremoteAPI\build\CMakeFiles\line_follower.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/line_follower.dir/depend
