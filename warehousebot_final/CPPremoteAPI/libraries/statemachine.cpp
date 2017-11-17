#include "statemachine.h"
#include "dock.h"

#define BLACK 0
#define RED 1
#define GREEN 2
#define BLUE 3
#define WHITE 4
#define YELLOW 5

#define STEP 0.2

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
    int color;
    int targetDock;
    while(isActive()) {
        switch(state) {
            case 0: // Start
                cout << "State 0" << endl;
                setSpeed(0, 0);
                state = 1;
            case 1: // Wait for instruction
                while(isActive()) {
                    getDockSignal();
                    for(int i = 0; i < 2; i++) {
                        if(loadSignal[i] == 1) {
                            targetDock = i;
                            while(true) {
                                 color = follow();
                                 if(color != dockColor[i]) forward(STEP); // Small forward step
                                 else {
                                    cout << "Ready to pick box at dock " << targetDock << "!" << endl;
                                    forward(STEP);
                                    setSpeed(0, 0);
                                    extApi_sleepMs(500);
                                    state = 2;
                                    break;
                                 }
                            }
                            break;
                        }
                    }
                    if(state != 1) break;
                }
                break;
            case 2: // Pick box
                cout << "State 2" << endl;
                cout << "Picking box at dock " << targetDock << "!" << endl;
                if(targetDock == 0)
                {
                    colorSignal[0] = RED; //red robot
                    colorSignal[1] = WHITE; //white box
                } else
                {
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
                    getDockSignal();
                    bool flag = true;
                    do {
                        // Search if the other dock is empty
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
                    do {
                        color = follow();
                        forward(STEP);
                    } while(color != dockColor[targetDock]);
                    cout << "Placing box at dock " << targetDock << "!" << endl;
                    setSpeed(0, 0);
                    extApi_sleepMs(500);
                    // Unloading
                    if(targetDock == 0)
                    {
                        colorSignal[2] = RED; //red box
                        colorSignal[0] = WHITE; //white robot
                        cout << "Set Dock 0 Unload: " << colorSignal[2] << endl;
                        
                    } else
                    {
                        colorSignal[4] = GREEN; //green box
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
    }
}
