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
        // Set newBoxHandles empty
        newBoxHandle[0] = -1;
        newBoxHandle[1] = -1;
        // Set both docks empty
        dockSignal[0] = DOCK_EMPTY;
        dockSignal[1] = DOCK_EMPTY;
        setDockSignal();
        for(int i = 0; i < 2; i++) {
            simxGetIntegerSignal(clientID, (const simxChar*) ("dockSignal" + to_string(i)).c_str(), (simxInt*) &dockSignal[i], simx_opmode_streaming);
        }
    }
    else {
        // Connection problems
        cout << "Unable to connect to server!" << endl;
    }    
}

Dock::~Dock() {
    // Close connection to server
    if(isActive()) {
        simxFinish(clientID);
        cout << "Connection closed!" << endl;
    }
}

bool Dock::isActive() {
    if(simxGetConnectionId(clientID) != -1) return true;
    else return false;
}

bool Dock::getDockSignal() {
    for(int i = 0; i < 2; i++) {
        if(simxGetIntegerSignal(clientID, (const simxChar*) ("dockSignal" + to_string(i)).c_str(), (simxInt*) &dockSignal[i], simx_opmode_buffer) != simx_return_ok) return false;
    } 
    return true;   
}

void Dock::setDockSignal() {
    for(int i = 0; i < 2; i++) {
        simxSetIntegerSignal(clientID, (const simxChar*) ("dockSignal" + to_string(i)).c_str(), (simxInt) dockSignal[i], simx_opmode_oneshot);
    }
}

bool Dock::spawnBox(int dockNumber) {
    simxInt* tempBoxHandle;
    int tempBoxCount;
    if(dockNumber != 0 && dockNumber != 1) {
        cout << "Invalid dock number detected" << endl;
        return false;
    }
    else {
        // Check if there already are boxes at that specific dock
        if(newBoxHandle[dockNumber] != -1) {
            cout << "This dock already has a box, wait the robot pick it" << endl;
            return false;
        }
        else {
            if(simxCopyPasteObjects(clientID, (const simxInt*) &boxHandle[dockNumber], 1, &tempBoxHandle, (simxInt*) &tempBoxCount, simx_opmode_oneshot_wait) == simx_return_ok) {
                // Get position for the first time
                simxFloat tempPos;
                simxGetObjectPosition(clientID, tempBoxHandle[0], -1, &tempPos, simx_opmode_streaming);
                // Store the handle
                newBoxHandle[dockNumber] = tempBoxHandle[0];
                // Flag availability of a new item
                dockSignal[dockNumber] = DOCK_NEWITEM;
                setDockSignal();
                return true;
            }
            else return false;
        }
    }
}

bool Dock::removeBox(int dockNumber) {
    if(dockNumber != 0 && dockNumber != 1) {
        cout << "Invalid dock number detected" << endl;
        return false;
    }
    else {
        // The box to be removed was always spawned on the opposite dock
        int boxNumber;
        if(dockNumber == 0) boxNumber = 1;
        else boxNumber = 0;
        // Check if the box to be removed was already spawned
        if(newBoxHandle[boxNumber] != -1) {
            float position[3];
            if(simxGetObjectPosition(clientID, (simxInt) newBoxHandle[boxNumber], -1, (simxFloat*) position, simx_opmode_buffer) != simx_return_ok) {
                cout << "Error retrieving box position" << endl;
                return false;
            }
            else {
                // Check if the robot has moved the box
                if(boxNumber == 0 && position[0] > 0 && position[1] > 0) {
                    // Box was not moved
                    cout << "There are no boxes available to remove" << endl;
                    return false;
                }
                else if(boxNumber == 1 && position[1] < 0 && position[1] < 0) {
                    // Box was not moved
                    cout << "There are no boxes available to remove" << endl;
                    return false;
                }
                else {
                    // Box was moved, OK to remove it
                    if(simxRemoveObject(clientID, (simxInt) newBoxHandle[boxNumber], simx_opmode_oneshot_wait) == simx_return_ok) {
                        // Clear the value
                        newBoxHandle[boxNumber] = -1;
                        // Flag empty dock
                        dockSignal[dockNumber] = DOCK_EMPTY;
                        setDockSignal();
                        return true;
                    }
                    else return false;
                }
            }
        }
        else {
            cout << "There are no boxes available to remove" << endl;
            return false;
        }
    }    
}




