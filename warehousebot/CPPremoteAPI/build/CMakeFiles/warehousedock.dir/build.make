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
include CMakeFiles/warehousedock.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/warehousedock.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/warehousedock.dir/flags.make

CMakeFiles/warehousedock.dir/warehousedock.cpp.obj: CMakeFiles/warehousedock.dir/flags.make
CMakeFiles/warehousedock.dir/warehousedock.cpp.obj: CMakeFiles/warehousedock.dir/includes_CXX.rsp
CMakeFiles/warehousedock.dir/warehousedock.cpp.obj: ../warehousedock.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/warehousedock.dir/warehousedock.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\warehousedock.dir\warehousedock.cpp.obj -c C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\warehousedock.cpp

CMakeFiles/warehousedock.dir/warehousedock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/warehousedock.dir/warehousedock.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\warehousedock.cpp > CMakeFiles\warehousedock.dir\warehousedock.cpp.i

CMakeFiles/warehousedock.dir/warehousedock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/warehousedock.dir/warehousedock.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\warehousedock.cpp -o CMakeFiles\warehousedock.dir\warehousedock.cpp.s

CMakeFiles/warehousedock.dir/warehousedock.cpp.obj.requires:

.PHONY : CMakeFiles/warehousedock.dir/warehousedock.cpp.obj.requires

CMakeFiles/warehousedock.dir/warehousedock.cpp.obj.provides: CMakeFiles/warehousedock.dir/warehousedock.cpp.obj.requires
	$(MAKE) -f CMakeFiles\warehousedock.dir\build.make CMakeFiles/warehousedock.dir/warehousedock.cpp.obj.provides.build
.PHONY : CMakeFiles/warehousedock.dir/warehousedock.cpp.obj.provides

CMakeFiles/warehousedock.dir/warehousedock.cpp.obj.provides.build: CMakeFiles/warehousedock.dir/warehousedock.cpp.obj


CMakeFiles/warehousedock.dir/remoteApi/extApi.c.obj: CMakeFiles/warehousedock.dir/flags.make
CMakeFiles/warehousedock.dir/remoteApi/extApi.c.obj: CMakeFiles/warehousedock.dir/includes_C.rsp
CMakeFiles/warehousedock.dir/remoteApi/extApi.c.obj: ../remoteApi/extApi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/warehousedock.dir/remoteApi/extApi.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\warehousedock.dir\remoteApi\extApi.c.obj   -c C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\remoteApi\extApi.c

CMakeFiles/warehousedock.dir/remoteApi/extApi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/warehousedock.dir/remoteApi/extApi.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\remoteApi\extApi.c > CMakeFiles\warehousedock.dir\remoteApi\extApi.c.i

CMakeFiles/warehousedock.dir/remoteApi/extApi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/warehousedock.dir/remoteApi/extApi.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\remoteApi\extApi.c -o CMakeFiles\warehousedock.dir\remoteApi\extApi.c.s

CMakeFiles/warehousedock.dir/remoteApi/extApi.c.obj.requires:

.PHONY : CMakeFiles/warehousedock.dir/remoteApi/extApi.c.obj.requires

CMakeFiles/warehousedock.dir/remoteApi/extApi.c.obj.provides: CMakeFiles/warehousedock.dir/remoteApi/extApi.c.obj.requires
	$(MAKE) -f CMakeFiles\warehousedock.dir\build.make CMakeFiles/warehousedock.dir/remoteApi/extApi.c.obj.provides.build
.PHONY : CMakeFiles/warehousedock.dir/remoteApi/extApi.c.obj.provides

CMakeFiles/warehousedock.dir/remoteApi/extApi.c.obj.provides.build: CMakeFiles/warehousedock.dir/remoteApi/extApi.c.obj


CMakeFiles/warehousedock.dir/remoteApi/extApiPlatform.c.obj: CMakeFiles/warehousedock.dir/flags.make
CMakeFiles/warehousedock.dir/remoteApi/extApiPlatform.c.obj: CMakeFiles/warehousedock.dir/includes_C.rsp
CMakeFiles/warehousedock.dir/remoteApi/extApiPlatform.c.obj: ../remoteApi/extApiPlatform.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/warehousedock.dir/remoteApi/extApiPlatform.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\warehousedock.dir\remoteApi\extApiPlatform.c.obj   -c C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\remoteApi\extApiPlatform.c

CMakeFiles/warehousedock.dir/remoteApi/extApiPlatform.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/warehousedock.dir/remoteApi/extApiPlatform.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\remoteApi\extApiPlatform.c > CMakeFiles\warehousedock.dir\remoteApi\extApiPlatform.c.i

CMakeFiles/warehousedock.dir/remoteApi/extApiPlatform.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/warehousedock.dir/remoteApi/extApiPlatform.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\remoteApi\extApiPlatform.c -o CMakeFiles\warehousedock.dir\remoteApi\extApiPlatform.c.s

CMakeFiles/warehousedock.dir/remoteApi/extApiPlatform.c.obj.requires:

.PHONY : CMakeFiles/warehousedock.dir/remoteApi/extApiPlatform.c.obj.requires

CMakeFiles/warehousedock.dir/remoteApi/extApiPlatform.c.obj.provides: CMakeFiles/warehousedock.dir/remoteApi/extApiPlatform.c.obj.requires
	$(MAKE) -f CMakeFiles\warehousedock.dir\build.make CMakeFiles/warehousedock.dir/remoteApi/extApiPlatform.c.obj.provides.build
.PHONY : CMakeFiles/warehousedock.dir/remoteApi/extApiPlatform.c.obj.provides

CMakeFiles/warehousedock.dir/remoteApi/extApiPlatform.c.obj.provides.build: CMakeFiles/warehousedock.dir/remoteApi/extApiPlatform.c.obj


CMakeFiles/warehousedock.dir/libraries/diffdrive.cpp.obj: CMakeFiles/warehousedock.dir/flags.make
CMakeFiles/warehousedock.dir/libraries/diffdrive.cpp.obj: CMakeFiles/warehousedock.dir/includes_CXX.rsp
CMakeFiles/warehousedock.dir/libraries/diffdrive.cpp.obj: ../libraries/diffdrive.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/warehousedock.dir/libraries/diffdrive.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\warehousedock.dir\libraries\diffdrive.cpp.obj -c C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\libraries\diffdrive.cpp

CMakeFiles/warehousedock.dir/libraries/diffdrive.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/warehousedock.dir/libraries/diffdrive.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\libraries\diffdrive.cpp > CMakeFiles\warehousedock.dir\libraries\diffdrive.cpp.i

CMakeFiles/warehousedock.dir/libraries/diffdrive.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/warehousedock.dir/libraries/diffdrive.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\libraries\diffdrive.cpp -o CMakeFiles\warehousedock.dir\libraries\diffdrive.cpp.s

CMakeFiles/warehousedock.dir/libraries/diffdrive.cpp.obj.requires:

.PHONY : CMakeFiles/warehousedock.dir/libraries/diffdrive.cpp.obj.requires

CMakeFiles/warehousedock.dir/libraries/diffdrive.cpp.obj.provides: CMakeFiles/warehousedock.dir/libraries/diffdrive.cpp.obj.requires
	$(MAKE) -f CMakeFiles\warehousedock.dir\build.make CMakeFiles/warehousedock.dir/libraries/diffdrive.cpp.obj.provides.build
.PHONY : CMakeFiles/warehousedock.dir/libraries/diffdrive.cpp.obj.provides

CMakeFiles/warehousedock.dir/libraries/diffdrive.cpp.obj.provides.build: CMakeFiles/warehousedock.dir/libraries/diffdrive.cpp.obj


CMakeFiles/warehousedock.dir/libraries/dock.cpp.obj: CMakeFiles/warehousedock.dir/flags.make
CMakeFiles/warehousedock.dir/libraries/dock.cpp.obj: CMakeFiles/warehousedock.dir/includes_CXX.rsp
CMakeFiles/warehousedock.dir/libraries/dock.cpp.obj: ../libraries/dock.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/warehousedock.dir/libraries/dock.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\warehousedock.dir\libraries\dock.cpp.obj -c C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\libraries\dock.cpp

CMakeFiles/warehousedock.dir/libraries/dock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/warehousedock.dir/libraries/dock.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\libraries\dock.cpp > CMakeFiles\warehousedock.dir\libraries\dock.cpp.i

CMakeFiles/warehousedock.dir/libraries/dock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/warehousedock.dir/libraries/dock.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\libraries\dock.cpp -o CMakeFiles\warehousedock.dir\libraries\dock.cpp.s

CMakeFiles/warehousedock.dir/libraries/dock.cpp.obj.requires:

.PHONY : CMakeFiles/warehousedock.dir/libraries/dock.cpp.obj.requires

CMakeFiles/warehousedock.dir/libraries/dock.cpp.obj.provides: CMakeFiles/warehousedock.dir/libraries/dock.cpp.obj.requires
	$(MAKE) -f CMakeFiles\warehousedock.dir\build.make CMakeFiles/warehousedock.dir/libraries/dock.cpp.obj.provides.build
.PHONY : CMakeFiles/warehousedock.dir/libraries/dock.cpp.obj.provides

CMakeFiles/warehousedock.dir/libraries/dock.cpp.obj.provides.build: CMakeFiles/warehousedock.dir/libraries/dock.cpp.obj


CMakeFiles/warehousedock.dir/libraries/linefollow.cpp.obj: CMakeFiles/warehousedock.dir/flags.make
CMakeFiles/warehousedock.dir/libraries/linefollow.cpp.obj: CMakeFiles/warehousedock.dir/includes_CXX.rsp
CMakeFiles/warehousedock.dir/libraries/linefollow.cpp.obj: ../libraries/linefollow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/warehousedock.dir/libraries/linefollow.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\warehousedock.dir\libraries\linefollow.cpp.obj -c C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\libraries\linefollow.cpp

CMakeFiles/warehousedock.dir/libraries/linefollow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/warehousedock.dir/libraries/linefollow.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\libraries\linefollow.cpp > CMakeFiles\warehousedock.dir\libraries\linefollow.cpp.i

CMakeFiles/warehousedock.dir/libraries/linefollow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/warehousedock.dir/libraries/linefollow.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\libraries\linefollow.cpp -o CMakeFiles\warehousedock.dir\libraries\linefollow.cpp.s

CMakeFiles/warehousedock.dir/libraries/linefollow.cpp.obj.requires:

.PHONY : CMakeFiles/warehousedock.dir/libraries/linefollow.cpp.obj.requires

CMakeFiles/warehousedock.dir/libraries/linefollow.cpp.obj.provides: CMakeFiles/warehousedock.dir/libraries/linefollow.cpp.obj.requires
	$(MAKE) -f CMakeFiles\warehousedock.dir\build.make CMakeFiles/warehousedock.dir/libraries/linefollow.cpp.obj.provides.build
.PHONY : CMakeFiles/warehousedock.dir/libraries/linefollow.cpp.obj.provides

CMakeFiles/warehousedock.dir/libraries/linefollow.cpp.obj.provides.build: CMakeFiles/warehousedock.dir/libraries/linefollow.cpp.obj


CMakeFiles/warehousedock.dir/libraries/robot.cpp.obj: CMakeFiles/warehousedock.dir/flags.make
CMakeFiles/warehousedock.dir/libraries/robot.cpp.obj: CMakeFiles/warehousedock.dir/includes_CXX.rsp
CMakeFiles/warehousedock.dir/libraries/robot.cpp.obj: ../libraries/robot.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/warehousedock.dir/libraries/robot.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\warehousedock.dir\libraries\robot.cpp.obj -c C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\libraries\robot.cpp

CMakeFiles/warehousedock.dir/libraries/robot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/warehousedock.dir/libraries/robot.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\libraries\robot.cpp > CMakeFiles\warehousedock.dir\libraries\robot.cpp.i

CMakeFiles/warehousedock.dir/libraries/robot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/warehousedock.dir/libraries/robot.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\libraries\robot.cpp -o CMakeFiles\warehousedock.dir\libraries\robot.cpp.s

CMakeFiles/warehousedock.dir/libraries/robot.cpp.obj.requires:

.PHONY : CMakeFiles/warehousedock.dir/libraries/robot.cpp.obj.requires

CMakeFiles/warehousedock.dir/libraries/robot.cpp.obj.provides: CMakeFiles/warehousedock.dir/libraries/robot.cpp.obj.requires
	$(MAKE) -f CMakeFiles\warehousedock.dir\build.make CMakeFiles/warehousedock.dir/libraries/robot.cpp.obj.provides.build
.PHONY : CMakeFiles/warehousedock.dir/libraries/robot.cpp.obj.provides

CMakeFiles/warehousedock.dir/libraries/robot.cpp.obj.provides.build: CMakeFiles/warehousedock.dir/libraries/robot.cpp.obj


CMakeFiles/warehousedock.dir/libraries/statemachine.cpp.obj: CMakeFiles/warehousedock.dir/flags.make
CMakeFiles/warehousedock.dir/libraries/statemachine.cpp.obj: CMakeFiles/warehousedock.dir/includes_CXX.rsp
CMakeFiles/warehousedock.dir/libraries/statemachine.cpp.obj: ../libraries/statemachine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/warehousedock.dir/libraries/statemachine.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\warehousedock.dir\libraries\statemachine.cpp.obj -c C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\libraries\statemachine.cpp

CMakeFiles/warehousedock.dir/libraries/statemachine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/warehousedock.dir/libraries/statemachine.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\libraries\statemachine.cpp > CMakeFiles\warehousedock.dir\libraries\statemachine.cpp.i

CMakeFiles/warehousedock.dir/libraries/statemachine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/warehousedock.dir/libraries/statemachine.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\libraries\statemachine.cpp -o CMakeFiles\warehousedock.dir\libraries\statemachine.cpp.s

CMakeFiles/warehousedock.dir/libraries/statemachine.cpp.obj.requires:

.PHONY : CMakeFiles/warehousedock.dir/libraries/statemachine.cpp.obj.requires

CMakeFiles/warehousedock.dir/libraries/statemachine.cpp.obj.provides: CMakeFiles/warehousedock.dir/libraries/statemachine.cpp.obj.requires
	$(MAKE) -f CMakeFiles\warehousedock.dir\build.make CMakeFiles/warehousedock.dir/libraries/statemachine.cpp.obj.provides.build
.PHONY : CMakeFiles/warehousedock.dir/libraries/statemachine.cpp.obj.provides

CMakeFiles/warehousedock.dir/libraries/statemachine.cpp.obj.provides.build: CMakeFiles/warehousedock.dir/libraries/statemachine.cpp.obj


# Object files for target warehousedock
warehousedock_OBJECTS = \
"CMakeFiles/warehousedock.dir/warehousedock.cpp.obj" \
"CMakeFiles/warehousedock.dir/remoteApi/extApi.c.obj" \
"CMakeFiles/warehousedock.dir/remoteApi/extApiPlatform.c.obj" \
"CMakeFiles/warehousedock.dir/libraries/diffdrive.cpp.obj" \
"CMakeFiles/warehousedock.dir/libraries/dock.cpp.obj" \
"CMakeFiles/warehousedock.dir/libraries/linefollow.cpp.obj" \
"CMakeFiles/warehousedock.dir/libraries/robot.cpp.obj" \
"CMakeFiles/warehousedock.dir/libraries/statemachine.cpp.obj"

# External object files for target warehousedock
warehousedock_EXTERNAL_OBJECTS =

warehousedock.exe: CMakeFiles/warehousedock.dir/warehousedock.cpp.obj
warehousedock.exe: CMakeFiles/warehousedock.dir/remoteApi/extApi.c.obj
warehousedock.exe: CMakeFiles/warehousedock.dir/remoteApi/extApiPlatform.c.obj
warehousedock.exe: CMakeFiles/warehousedock.dir/libraries/diffdrive.cpp.obj
warehousedock.exe: CMakeFiles/warehousedock.dir/libraries/dock.cpp.obj
warehousedock.exe: CMakeFiles/warehousedock.dir/libraries/linefollow.cpp.obj
warehousedock.exe: CMakeFiles/warehousedock.dir/libraries/robot.cpp.obj
warehousedock.exe: CMakeFiles/warehousedock.dir/libraries/statemachine.cpp.obj
warehousedock.exe: CMakeFiles/warehousedock.dir/build.make
warehousedock.exe: CMakeFiles/warehousedock.dir/linklibs.rsp
warehousedock.exe: CMakeFiles/warehousedock.dir/objects1.rsp
warehousedock.exe: CMakeFiles/warehousedock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable warehousedock.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\warehousedock.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/warehousedock.dir/build: warehousedock.exe

.PHONY : CMakeFiles/warehousedock.dir/build

CMakeFiles/warehousedock.dir/requires: CMakeFiles/warehousedock.dir/warehousedock.cpp.obj.requires
CMakeFiles/warehousedock.dir/requires: CMakeFiles/warehousedock.dir/remoteApi/extApi.c.obj.requires
CMakeFiles/warehousedock.dir/requires: CMakeFiles/warehousedock.dir/remoteApi/extApiPlatform.c.obj.requires
CMakeFiles/warehousedock.dir/requires: CMakeFiles/warehousedock.dir/libraries/diffdrive.cpp.obj.requires
CMakeFiles/warehousedock.dir/requires: CMakeFiles/warehousedock.dir/libraries/dock.cpp.obj.requires
CMakeFiles/warehousedock.dir/requires: CMakeFiles/warehousedock.dir/libraries/linefollow.cpp.obj.requires
CMakeFiles/warehousedock.dir/requires: CMakeFiles/warehousedock.dir/libraries/robot.cpp.obj.requires
CMakeFiles/warehousedock.dir/requires: CMakeFiles/warehousedock.dir/libraries/statemachine.cpp.obj.requires

.PHONY : CMakeFiles/warehousedock.dir/requires

CMakeFiles/warehousedock.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\warehousedock.dir\cmake_clean.cmake
.PHONY : CMakeFiles/warehousedock.dir/clean

CMakeFiles/warehousedock.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\build C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\build C:\Users\victo\Git\engsoft\warehousebot\CPPremoteAPI\build\CMakeFiles\warehousedock.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/warehousedock.dir/depend

