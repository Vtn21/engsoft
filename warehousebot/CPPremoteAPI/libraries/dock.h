#ifndef DOCK_H_
#define DOCK_H_

#define DOCK_EMPTY 0
#define DOCK_FULL 1
#define DOCK_NEWITEM 2

extern "C" {
    #include <extApi.h>
}

#include <iostream>
#include <string>

#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

const int dockColor[] = {1, 3};

class Dock {
private:
    // Server parameters
    string serverIP;
    int serverPort;
    int clientID;
    // Default boxes
    string boxName[2];
    int boxHandle[2];
    // New boxes
    int newBoxHandle[2];
    // Dock signal (refer to #define's)
    int dockSignal[2];
    // Signal to store the handle of the box associated with each dock
    int dockBoxHandleSignal[2];
public:
    Dock();
    ~Dock();
    bool isActive();
    void getDockSignal();
    void setDockSignal();
    void getDockBoxHandleSignal();
    void setDockBoxHandleSignal();
    bool spawnBox(int dockNumber);
    bool removeBox(int dockNumber);
};

#endif // DOCK_H_