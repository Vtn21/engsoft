#include "statemachine.h"
#include "dock.h"

#define BLACK 0
#define RED 1
#define GREEN 2
#define BLUE 3
#define WHITE 4
#define YELLOW 5

StateMachine::StateMachine(): LineFollow() {
    state = 0;
    if(isActive()) {
        // Connect to the full robot
        if(simxGetObjectHandle(clientID, (const simxChar*) "Pioneer_p3dx", (simxInt *) &robotHandle, (simxInt) simx_opmode_oneshot_wait) != simx_return_ok) cout << "Pioneer_p3dx handle not found!" << endl;
        else cout << "Connected to Pioneer_p3dx!" << endl;
    }
    // Get signals for the first time
    for(int i = 0; i < 2; i++) {
        simxGetIntegerSignal(clientID, (const simxChar*) ("loadSignal" + to_string(i)).c_str(), (simxInt*) &loadSignal[i], simx_opmode_streaming);
        simxGetIntegerSignal(clientID, (const simxChar*) ("unloadSignal" + to_string(i)).c_str(), (simxInt*) &unloadSignal[i], simx_opmode_streaming);
    }
    // Get signals for the first time
    simxGetIntegerSignal(clientID, (const simxChar*) ("robotColor"), (simxInt*) &colorSignal[0], simx_opmode_streaming);
    simxGetIntegerSignal(clientID, (const simxChar*) ("dock0LoadColor"), (simxInt*) &colorSignal[1], simx_opmode_streaming);
    simxGetIntegerSignal(clientID, (const simxChar*) ("dock0UnloadColor"), (simxInt*) &colorSignal[2], simx_opmode_streaming);
    simxGetIntegerSignal(clientID, (const simxChar*) ("dock1LoadColor"), (simxInt*) &colorSignal[3], simx_opmode_streaming);
    simxGetIntegerSignal(clientID, (const simxChar*) ("dock1UnloadColor"), (simxInt*) &colorSignal[4], simx_opmode_streaming);
    // Set docks empty
    for(int i = 0; i < 2; i++) {
        loadSignal[i] = 0;
        unloadSignal[i] = 0;
    }
    setDockSignal();
}

StateMachine::~StateMachine() {}

void StateMachine::getDockSignal() {
    for(int i = 0; i < 2; i++) {
        simxGetIntegerSignal(clientID, (const simxChar*) ("loadSignal" + to_string(i)).c_str(), (simxInt*) &loadSignal[i], simx_opmode_buffer);
        simxGetIntegerSignal(clientID, (const simxChar*) ("unloadSignal" + to_string(i)).c_str(), (simxInt*) &unloadSignal[i], simx_opmode_buffer);
    }
}

void StateMachine::setDockSignal() {
    for(int i = 0; i < 2; i++) {
        simxSetIntegerSignal(clientID, (const simxChar*) ("loadSignal" + to_string(i)).c_str(), (simxInt) loadSignal[i], simx_opmode_oneshot);
        simxSetIntegerSignal(clientID, (const simxChar*) ("unloadSignal" + to_string(i)).c_str(), (simxInt) unloadSignal[i], simx_opmode_oneshot);
    }
}

void StateMachine::getColorSignal() {
    simxGetIntegerSignal(clientID, (const simxChar*) ("robotColor"), (simxInt*) &colorSignal[0], simx_opmode_buffer);
    simxGetIntegerSignal(clientID, (const simxChar*) ("dock0LoadColor"), (simxInt*) &colorSignal[1], simx_opmode_buffer);
    simxGetIntegerSignal(clientID, (const simxChar*) ("dock0UnloadColor"), (simxInt*) &colorSignal[2], simx_opmode_buffer);
    simxGetIntegerSignal(clientID, (const simxChar*) ("dock1LoadColor"), (simxInt*) &colorSignal[3], simx_opmode_buffer);
    simxGetIntegerSignal(clientID, (const simxChar*) ("dock1UnloadColor"), (simxInt*) &colorSignal[4], simx_opmode_buffer);
}

void StateMachine::setColorSignal() {
    simxSetIntegerSignal(clientID, (const simxChar*) ("robotColor"), (simxInt) colorSignal[0], simx_opmode_oneshot);
    simxSetIntegerSignal(clientID, (const simxChar*) ("dock0LoadColor"), (simxInt) colorSignal[1], simx_opmode_oneshot);
    simxSetIntegerSignal(clientID, (const simxChar*) ("dock0UnloadColor"), (simxInt) colorSignal[2], simx_opmode_oneshot);
    simxSetIntegerSignal(clientID, (const simxChar*) ("dock1LoadColor"), (simxInt) colorSignal[3], simx_opmode_oneshot);
    simxSetIntegerSignal(clientID, (const simxChar*) ("dock1UnloadColor"), (simxInt) colorSignal[4], simx_opmode_oneshot);
}

void StateMachine::run() {
    int targetDock;
    while(isActive()) {
        if(getBatteryLevel() > BATTERY_CRITICAL)
        {
            switch(state) {
                case 0: // Start
                    cout << "State 0" << endl;
                    setSpeed(0, 0);
                    getDockSignal();
                    getColorSignal();
                    state = 1;
                    break;
                case 1: // Wait for instruction
                    while(isActive()) {
                        getDockSignal();
                        for(int i = 0; i < 2; i++) {
                            if(loadSignal[i] == 1) {
                                targetDock = i;
                                followUntilColor(dockColor[targetDock]);
                                cout << "Ready to pick box at dock " << targetDock << "!" << endl;
                                extApi_sleepMs(500);
                                state = 2;
                                break;
                            }
                        }
                        if(state != 1) break;
                    }
                    break;
                case 2: // Pick box
                    cout << "State 2" << endl;
                    cout << "Picking box at dock " << targetDock << "!" << endl;
                    getDockSignal();
                    getColorSignal();
                    if(targetDock == 0) {
                        colorSignal[0] = RED; //red robot
                        colorSignal[1] = WHITE; //white box
                    }
                    else {
                        colorSignal[0] = GREEN; //green robot
                        colorSignal[3] = WHITE; //white box
                    }
                    setColorSignal();
                    loadSignal[targetDock] = 0;
                    setDockSignal();
                    state = 3; // Next state: place the recently picked box
                    break;
                case 3: // Place box
                    cout << "State 3" << endl;
                    while(isActive()) {
                        bool flag = true;
                        do {
                            // Search if the other dock is empty
                            getDockSignal();
                            for(int i = 0; i < 2; i++) {
                                if(i != targetDock && unloadSignal[i] == 0) {
                                    // Dock is empty
                                    targetDock = i;
                                    flag = false;
                                    break;
                                }
                            }
                        } while(flag);
                        // Go to the other dock
                        followUntilColor(dockColor[targetDock]);
                        cout << "Placing box at dock " << targetDock << "!" << endl;
                        extApi_sleepMs(500);
                        // Unloading
                        getDockSignal();
                        getColorSignal();
                        if(targetDock == 0) {
                            colorSignal[2] = GREEN; //green box
                            colorSignal[0] = WHITE; //white robot
                            cout << "Set Dock 0 Unload: " << colorSignal[2] << endl;
                        } else {
                            colorSignal[4] = RED; //red box
                            colorSignal[0] = WHITE; //white robot
                            cout << "Set Dock 1 Unload: " << colorSignal[4] << endl;
                        }
                        setColorSignal();
                        unloadSignal[targetDock] = 1;
                        setDockSignal();
                        state = 0; // Next state: wait for instruction
                        break;
                    }
                    break;
            }
        } else
        {
            cout << "Battery needs charging!" << endl;
            followUntilColor(YELLOW);
            setSpeed(0, 0);
            cout << "Recharging..." << endl;
            extApi_sleepMs(3000);
            simxSetFloatSignal(clientID, "batteryLevel", (simxFloat) 100.0, simx_opmode_oneshot);
            cout << "Battery fully charged!" << endl;
        }
    }
}
