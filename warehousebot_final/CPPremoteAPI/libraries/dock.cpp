#include "dock.h"

Dock::Dock() {
    // Assign default values to server parameters
    serverIP = "127.0.0.1";
    serverPort = 20000;
    // Start communication
    clientID = simxStart((simxChar*) serverIP.c_str(), serverPort, true, true, 2000, 5);
    if(clientID != -1) {
        // Connection OK
        cout << "Server connected!" << endl;
        // Set all docks empty
        loadSignal[0] = 0;
        loadSignal[1] = 0;
        unloadSignal[0] = 0;
        unloadSignal[1] = 0;
        setDockSignal();
        // Get signals for the first time
        for(int i = 0; i < 2; i++) {
            simxGetIntegerSignal(clientID, (const simxChar*) ("loadSignal" + to_string(i)).c_str(), (simxInt*) &loadSignal[i], simx_opmode_streaming);
            simxGetIntegerSignal(clientID, (const simxChar*) ("unloadSignal" + to_string(i)).c_str(), (simxInt*) &unloadSignal[i], simx_opmode_streaming);
        }
        // Set all boxes white
        for(int i = 0; i < 5; i++) {
            colorSignal[i] = WHITE;
        } 
        // Get signals for the first time
        setColorSignal();
        simxGetIntegerSignal(clientID, (const simxChar*) ("robotColor"), (simxInt*) &colorSignal[0], simx_opmode_streaming);
        simxGetIntegerSignal(clientID, (const simxChar*) ("dock0LoadColor"), (simxInt*) &colorSignal[1], simx_opmode_streaming);
        simxGetIntegerSignal(clientID, (const simxChar*) ("dock0UnloadColor"), (simxInt*) &colorSignal[2], simx_opmode_streaming);
        simxGetIntegerSignal(clientID, (const simxChar*) ("dock1LoadColor"), (simxInt*) &colorSignal[3], simx_opmode_streaming);
        simxGetIntegerSignal(clientID, (const simxChar*) ("dock1UnloadColor"), (simxInt*) &colorSignal[4], simx_opmode_streaming);
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

void Dock::getDockSignal() {
    for(int i = 0; i < 2; i++) {
        simxGetIntegerSignal(clientID, (const simxChar*) ("loadSignal" + to_string(i)).c_str(), (simxInt*) &loadSignal[i], simx_opmode_buffer);
        simxGetIntegerSignal(clientID, (const simxChar*) ("unloadSignal" + to_string(i)).c_str(), (simxInt*) &unloadSignal[i], simx_opmode_buffer);
    }
}

void Dock::setDockSignal() {
    for(int i = 0; i < 2; i++) {
        simxSetIntegerSignal(clientID, (const simxChar*) ("loadSignal" + to_string(i)).c_str(), (simxInt) loadSignal[i], simx_opmode_oneshot);
        simxSetIntegerSignal(clientID, (const simxChar*) ("unloadSignal" + to_string(i)).c_str(), (simxInt) unloadSignal[i], simx_opmode_oneshot);
    }
}

void Dock::getColorSignal() {
    simxGetIntegerSignal(clientID, (const simxChar*) ("robotColor"), (simxInt*) &colorSignal[0], simx_opmode_buffer);
    simxGetIntegerSignal(clientID, (const simxChar*) ("dock0LoadColor"), (simxInt*) &colorSignal[1], simx_opmode_buffer);
    simxGetIntegerSignal(clientID, (const simxChar*) ("dock0UnloadColor"), (simxInt*) &colorSignal[2], simx_opmode_buffer);
    simxGetIntegerSignal(clientID, (const simxChar*) ("dock1LoadColor"), (simxInt*) &colorSignal[3], simx_opmode_buffer);
    simxGetIntegerSignal(clientID, (const simxChar*) ("dock1UnloadColor"), (simxInt*) &colorSignal[4], simx_opmode_buffer);
}

void Dock::setColorSignal() {
    simxSetIntegerSignal(clientID, (const simxChar*) ("robotColor"), (simxInt) colorSignal[0], simx_opmode_oneshot);
    simxSetIntegerSignal(clientID, (const simxChar*) ("dock0LoadColor"), (simxInt) colorSignal[1], simx_opmode_oneshot);
    simxSetIntegerSignal(clientID, (const simxChar*) ("dock0UnloadColor"), (simxInt) colorSignal[2], simx_opmode_oneshot);
    simxSetIntegerSignal(clientID, (const simxChar*) ("dock1LoadColor"), (simxInt) colorSignal[3], simx_opmode_oneshot);
    simxSetIntegerSignal(clientID, (const simxChar*) ("dock1UnloadColor"), (simxInt) colorSignal[4], simx_opmode_oneshot);
}

bool Dock::spawnBox(int dockNumber) {
    if(dockNumber != 0 && dockNumber != 1) {
        cout << "Invalid dock number detected" << endl;
        return false;
    }
    else {
        // Check if there already are boxes at that specific dock
        getDockSignal();
        if(loadSignal[dockNumber] == 1) {
            cout << "This dock already has a box, wait the robot pick it" << endl;
            return false;
        }
        else {
            // Change dock color
            if(dockNumber == 0) colorSignal[1] = RED;
            else colorSignal[3] = GREEN;
            setColorSignal();
            // Flag availability of a new item
            loadSignal[dockNumber] = 1;
            setDockSignal();
            return true;
        }
    }
}

bool Dock::removeBox(int dockNumber) {
    if(dockNumber != 0 && dockNumber != 1) {
        cout << "Invalid dock number detected" << endl;
        return false;
    }
    else {
        // Check if there already are boxes at that specific dock
        getDockSignal();
        if(unloadSignal[dockNumber] == 0) {
            cout << "Nothing to be removed from Dock " << dockNumber << endl;
            return false;
        }
        else {
            // Change dock color
            if(dockNumber == 0) colorSignal[2] = WHITE;
            else colorSignal[4] = WHITE;
            setColorSignal();
            // Flag item removal
            unloadSignal[dockNumber] = 0;
            setDockSignal();
            return true;
        }
    }    
}




