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
CMAKE_SOURCE_DIR = C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\build

# Include any dependencies generated for this target.
include CMakeFiles/warehousebot.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/warehousebot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/warehousebot.dir/flags.make

CMakeFiles/warehousebot.dir/warehousebot.cpp.obj: CMakeFiles/warehousebot.dir/flags.make
CMakeFiles/warehousebot.dir/warehousebot.cpp.obj: CMakeFiles/warehousebot.dir/includes_CXX.rsp
CMakeFiles/warehousebot.dir/warehousebot.cpp.obj: ../warehousebot.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/warehousebot.dir/warehousebot.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\warehousebot.dir\warehousebot.cpp.obj -c C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\warehousebot.cpp

CMakeFiles/warehousebot.dir/warehousebot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/warehousebot.dir/warehousebot.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\warehousebot.cpp > CMakeFiles\warehousebot.dir\warehousebot.cpp.i

CMakeFiles/warehousebot.dir/warehousebot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/warehousebot.dir/warehousebot.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\warehousebot.cpp -o CMakeFiles\warehousebot.dir\warehousebot.cpp.s

CMakeFiles/warehousebot.dir/warehousebot.cpp.obj.requires:

.PHONY : CMakeFiles/warehousebot.dir/warehousebot.cpp.obj.requires

CMakeFiles/warehousebot.dir/warehousebot.cpp.obj.provides: CMakeFiles/warehousebot.dir/warehousebot.cpp.obj.requires
	$(MAKE) -f CMakeFiles\warehousebot.dir\build.make CMakeFiles/warehousebot.dir/warehousebot.cpp.obj.provides.build
.PHONY : CMakeFiles/warehousebot.dir/warehousebot.cpp.obj.provides

CMakeFiles/warehousebot.dir/warehousebot.cpp.obj.provides.build: CMakeFiles/warehousebot.dir/warehousebot.cpp.obj


CMakeFiles/warehousebot.dir/remoteApi/extApi.c.obj: CMakeFiles/warehousebot.dir/flags.make
CMakeFiles/warehousebot.dir/remoteApi/extApi.c.obj: CMakeFiles/warehousebot.dir/includes_C.rsp
CMakeFiles/warehousebot.dir/remoteApi/extApi.c.obj: ../remoteApi/extApi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/warehousebot.dir/remoteApi/extApi.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\warehousebot.dir\remoteApi\extApi.c.obj   -c C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\remoteApi\extApi.c

CMakeFiles/warehousebot.dir/remoteApi/extApi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/warehousebot.dir/remoteApi/extApi.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\remoteApi\extApi.c > CMakeFiles\warehousebot.dir\remoteApi\extApi.c.i

CMakeFiles/warehousebot.dir/remoteApi/extApi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/warehousebot.dir/remoteApi/extApi.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\remoteApi\extApi.c -o CMakeFiles\warehousebot.dir\remoteApi\extApi.c.s

CMakeFiles/warehousebot.dir/remoteApi/extApi.c.obj.requires:

.PHONY : CMakeFiles/warehousebot.dir/remoteApi/extApi.c.obj.requires

CMakeFiles/warehousebot.dir/remoteApi/extApi.c.obj.provides: CMakeFiles/warehousebot.dir/remoteApi/extApi.c.obj.requires
	$(MAKE) -f CMakeFiles\warehousebot.dir\build.make CMakeFiles/warehousebot.dir/remoteApi/extApi.c.obj.provides.build
.PHONY : CMakeFiles/warehousebot.dir/remoteApi/extApi.c.obj.provides

CMakeFiles/warehousebot.dir/remoteApi/extApi.c.obj.provides.build: CMakeFiles/warehousebot.dir/remoteApi/extApi.c.obj


CMakeFiles/warehousebot.dir/remoteApi/extApiPlatform.c.obj: CMakeFiles/warehousebot.dir/flags.make
CMakeFiles/warehousebot.dir/remoteApi/extApiPlatform.c.obj: CMakeFiles/warehousebot.dir/includes_C.rsp
CMakeFiles/warehousebot.dir/remoteApi/extApiPlatform.c.obj: ../remoteApi/extApiPlatform.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/warehousebot.dir/remoteApi/extApiPlatform.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\warehousebot.dir\remoteApi\extApiPlatform.c.obj   -c C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\remoteApi\extApiPlatform.c

CMakeFiles/warehousebot.dir/remoteApi/extApiPlatform.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/warehousebot.dir/remoteApi/extApiPlatform.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\remoteApi\extApiPlatform.c > CMakeFiles\warehousebot.dir\remoteApi\extApiPlatform.c.i

CMakeFiles/warehousebot.dir/remoteApi/extApiPlatform.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/warehousebot.dir/remoteApi/extApiPlatform.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\remoteApi\extApiPlatform.c -o CMakeFiles\warehousebot.dir\remoteApi\extApiPlatform.c.s

CMakeFiles/warehousebot.dir/remoteApi/extApiPlatform.c.obj.requires:

.PHONY : CMakeFiles/warehousebot.dir/remoteApi/extApiPlatform.c.obj.requires

CMakeFiles/warehousebot.dir/remoteApi/extApiPlatform.c.obj.provides: CMakeFiles/warehousebot.dir/remoteApi/extApiPlatform.c.obj.requires
	$(MAKE) -f CMakeFiles\warehousebot.dir\build.make CMakeFiles/warehousebot.dir/remoteApi/extApiPlatform.c.obj.provides.build
.PHONY : CMakeFiles/warehousebot.dir/remoteApi/extApiPlatform.c.obj.provides

CMakeFiles/warehousebot.dir/remoteApi/extApiPlatform.c.obj.provides.build: CMakeFiles/warehousebot.dir/remoteApi/extApiPlatform.c.obj


CMakeFiles/warehousebot.dir/libraries/dock.cpp.obj: CMakeFiles/warehousebot.dir/flags.make
CMakeFiles/warehousebot.dir/libraries/dock.cpp.obj: CMakeFiles/warehousebot.dir/includes_CXX.rsp
CMakeFiles/warehousebot.dir/libraries/dock.cpp.obj: ../libraries/dock.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/warehousebot.dir/libraries/dock.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\warehousebot.dir\libraries\dock.cpp.obj -c C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\libraries\dock.cpp

CMakeFiles/warehousebot.dir/libraries/dock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/warehousebot.dir/libraries/dock.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\libraries\dock.cpp > CMakeFiles\warehousebot.dir\libraries\dock.cpp.i

CMakeFiles/warehousebot.dir/libraries/dock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/warehousebot.dir/libraries/dock.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\libraries\dock.cpp -o CMakeFiles\warehousebot.dir\libraries\dock.cpp.s

CMakeFiles/warehousebot.dir/libraries/dock.cpp.obj.requires:

.PHONY : CMakeFiles/warehousebot.dir/libraries/dock.cpp.obj.requires

CMakeFiles/warehousebot.dir/libraries/dock.cpp.obj.provides: CMakeFiles/warehousebot.dir/libraries/dock.cpp.obj.requires
	$(MAKE) -f CMakeFiles\warehousebot.dir\build.make CMakeFiles/warehousebot.dir/libraries/dock.cpp.obj.provides.build
.PHONY : CMakeFiles/warehousebot.dir/libraries/dock.cpp.obj.provides

CMakeFiles/warehousebot.dir/libraries/dock.cpp.obj.provides.build: CMakeFiles/warehousebot.dir/libraries/dock.cpp.obj


# Object files for target warehousebot
warehousebot_OBJECTS = \
"CMakeFiles/warehousebot.dir/warehousebot.cpp.obj" \
"CMakeFiles/warehousebot.dir/remoteApi/extApi.c.obj" \
"CMakeFiles/warehousebot.dir/remoteApi/extApiPlatform.c.obj" \
"CMakeFiles/warehousebot.dir/libraries/dock.cpp.obj"

# External object files for target warehousebot
warehousebot_EXTERNAL_OBJECTS =

warehousebot.exe: CMakeFiles/warehousebot.dir/warehousebot.cpp.obj
warehousebot.exe: CMakeFiles/warehousebot.dir/remoteApi/extApi.c.obj
warehousebot.exe: CMakeFiles/warehousebot.dir/remoteApi/extApiPlatform.c.obj
warehousebot.exe: CMakeFiles/warehousebot.dir/libraries/dock.cpp.obj
warehousebot.exe: CMakeFiles/warehousebot.dir/build.make
warehousebot.exe: CMakeFiles/warehousebot.dir/linklibs.rsp
warehousebot.exe: CMakeFiles/warehousebot.dir/objects1.rsp
warehousebot.exe: CMakeFiles/warehousebot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable warehousebot.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\warehousebot.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/warehousebot.dir/build: warehousebot.exe

.PHONY : CMakeFiles/warehousebot.dir/build

CMakeFiles/warehousebot.dir/requires: CMakeFiles/warehousebot.dir/warehousebot.cpp.obj.requires
CMakeFiles/warehousebot.dir/requires: CMakeFiles/warehousebot.dir/remoteApi/extApi.c.obj.requires
CMakeFiles/warehousebot.dir/requires: CMakeFiles/warehousebot.dir/remoteApi/extApiPlatform.c.obj.requires
CMakeFiles/warehousebot.dir/requires: CMakeFiles/warehousebot.dir/libraries/dock.cpp.obj.requires

.PHONY : CMakeFiles/warehousebot.dir/requires

CMakeFiles/warehousebot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\warehousebot.dir\cmake_clean.cmake
.PHONY : CMakeFiles/warehousebot.dir/clean

CMakeFiles/warehousebot.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\build C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\build C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\build\CMakeFiles\warehousebot.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/warehousebot.dir/depend

