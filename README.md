# README #

### What is this repository for? ###

* Code for Software Engineering project
* Autonomous warehouse robot, with user-controllable item spawning and removing

### Programming languages ###
* C++ using V-REP Remote API
* Lua (V-REP custom scripts)

### Required software ###

* Git CLI or GUI for cloning repository
* MinGW for building on Windows
* CMake for building on Windows or Linux
* V-REP for opening the scene

### Windows setup ###

* Open command prompt at engsoft\warehouse\CPPremoteAPI\build
* Run "cmake -G "MinGW Makefiles" .." to create Makefile
* Run "mingw32-make" to build
* Open engsoft\warehouse\warehouse.ttt using V-REP
* Play V-REP simulation, then run warehousedock.exe, warehousebot.exe and warehousebattery.exe

### Linux setup ###

* Open terminal at engsoft/warehouse/CPPremoteAPI/build
* Run "cmake .." to create Makefile
* Run "make" to build
* Open engsoft/warehouse/warehouse.ttt using V-REP
* Play V-REP simulation, then run ./warehousedock, ./warehousebot and ./warehousebattery

### Usage ###
* Spawn and remove boxes using the warehousedock.exe interface
* Monitor battery level using warehousebattery.exe

### V-REP scene information ###
* Red dot: dock #0
* Green dot: dock #1
* Blue dot: robot start
* Yellow dot: recharge
* Robot front box: payload
* Robot rear box: battery indicator
* Inner dock boxes: load
* Outer dock boxes: unload

### Who do I talk to? ###

* Eduardo Scheffer (Scheffer888): admin
* Leonardo Luís da Silva (leo1397): admin
* Matheus Scherma (mscherma): admin
* Victor Noppeney (vtn21): owner