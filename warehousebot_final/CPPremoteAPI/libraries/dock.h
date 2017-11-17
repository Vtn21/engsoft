#ifndef DOCK_H_
#define DOCK_H_

#define BLACK 0
#define RED 1
#define GREEN 2
#define BLUE 3
#define WHITE 4

extern "C" {
    #include <extApi.h>
}

#include <iostream>
#include <string>

#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

const int dockColor[] = {1, 2};

class Dock {
private:
    // Server parameters
    string serverIP;
    int serverPort;
    int clientID;
    // Dock signals
    int loadSignal[2];
    int unloadSignal[2];
    // Color of robot, and box (dock0L, dock0U, dock1L, dock1U), respectively
    int colorSignal[5];
public:
    Dock();
    ~Dock();
    bool isActive();
    void getDockSignal();
    void setDockSignal();
    void getColorSignal();
    void setColorSignal();
    bool spawnBox(int dockNumber);
    bool removeBox(int dockNumber);
};

#endif // DOCK_H_
