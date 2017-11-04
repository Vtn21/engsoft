#include "dock.h"

Dock::Dock() {
    // Assign default values to server parameters
    serverIP = "127.0.0.1";
    serverPort = 19999;
    // Start communication
    clientID = simxStart((simxChar*) serverIP.c_str(), serverPort, true, true, 2000, 5);
    if(clientID != -1) {
        // Connection OK
        cout << "Server connected!" << endl;
        // Connect to default boxes
        for(int i = 0; i < 2; i++) {
            boxName[i] = "Box" + to_string(i);
            if(simxGetObjectHandle(clientID, (const simxChar*) boxName[i].c_str(), (simxInt*) &boxHandle[i], (simxInt) simx_opmode_oneshot_wait) != simx_return_ok)
                cout << boxName[i] << " handle not found!" << endl;
            else
                cout << "Connected to " << boxName[i] << "!" << endl;    
        }
    }
    else {
        // Connection problems
        cout << "Unable to connect to server!" << endl;
    }
    dockSignal = {DOCK_EMPTY, DOCK_EMPTY};
    setDockSignal();
    for(int i = 0; i < 2; i++) {
        if(simxGetIntegerSignal(clientID, (const simxChar*) ("dockSignal" + to_string(i)).c_str()), &dockSignal[i], simx_opmode_streaming) != simx_return_ok) return false;
    }
}

Dock::~Dock() {
    // Close connection to server
    if(isActive()) {
        simxFinish(clientID);
        cout << "Connection closed!" << endl;
    }
}

bool Robot::isActive() {
    if(simxGetConnectionId(clientID) != -1) return true;
    else return false;
}

bool getDockSignal() {
    for(int i = 0; i < 2; i++) {
        if(simxGetIntegerSignal(clientID, (const simxChar*) ("dockSignal" + to_string(i)).c_str()), &dockSignal[i], simx_opmode_buffer) != simx_return_ok) return false;
    } 
    return true;   
}

bool setDockSignal() {
    for(int i = 0; i < 2; i++) {
        if(simxSetIntegerSignal(clientID, (const simxChar*) ("dockSignal" + to_string(i)).c_str()), dockSignal[i], simx_opmode_oneshot) != simx_return_ok) return false;
    }
    return true;
}

bool Dock::spawnItem(uint16_t dockNumber) {
    if(dockNumber != 0 && dockNumber != 1) {
        cout << "Invalid dock number detected" << endl;
        return false;
    }
    else {
        simxCopyPasteObjects(clientID, )
    }
}




