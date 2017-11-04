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

uint16_t dockColor[] = {1, 3};

class Dock {
private:
    // Server parameters
    string serverIP;
    int serverPort;
    // Default boxes
    string boxName[2];
    int boxHandle[2];
    // Dock signal (refer to #define's)
    uint16_t dockSignal[2];
public:
    Dock();
    ~Dock();
    bool isActive();
    bool getDockSignal();
    bool setDockSignal();
    bool spawnItem(uint16_t dockNumber);
};

#endif // DOCK_H_