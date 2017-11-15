#include "statemachine.h"
#include "dock.h"

#define BLACK 0
#define RED 1
#define GREEN 2
#define BLUE 3
#define YELLOW 4
#define OTHER 5

#define STEP 0.22
#define DOCK_DISTANCE 0.2

StateMachine::StateMachine(): LineFollow() {
    state = 0;
    if(isActive()) {
        // Connect to the full robot
        if(simxGetObjectHandle(clientID, (const simxChar*) "Pioneer_p3dx", (simxInt *) &robotHandle, (simxInt) simx_opmode_oneshot_wait) != simx_return_ok)
            cout << "Pioneer_p3dx handle not found!" << endl;
        else
            cout << "Connected to Pioneer_p3dx!" << endl;
    }
}

StateMachine::~StateMachine() {}

void StateMachine::getDockSignal() {
    for(int i = 0; i < 2; i++) {
        simxGetIntegerSignal(clientID, (const simxChar*) ("dockSignal" + to_string(i)).c_str(), (simxInt*) &dockSignal[i], simx_opmode_streaming);
    }
}

void StateMachine::setDockSignal() {
    for(int i = 0; i < 2; i++) {
        simxSetIntegerSignal(clientID, (const simxChar*) ("dockSignal" + to_string(i)).c_str(), (simxInt) dockSignal[i], simx_opmode_oneshot);
    }
}

void StateMachine::getNewBoxSignal() {
    for(int i = 0; i < 2; i++) {
        simxGetIntegerSignal(clientID, (const simxChar*) ("newBoxSignal" + to_string(i)).c_str(), (simxInt*) &newBoxSignal[i], simx_opmode_streaming);
    }
}

void StateMachine::setNewBoxSignal() {
    for(int i = 0; i < 2; i++) {
        simxSetIntegerSignal(clientID, (const simxChar*) ("newBoxSignal" + to_string(i)).c_str(), (simxInt) newBoxSignal[i], simx_opmode_oneshot);
    }
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
                cout << "State 1" << endl;
                while(isActive()) {
                    getDockSignal();
                    for(int i = 0; i < 2; i++) {
                        cout << "DockSignal#" << i << ": " << dockSignal[i] << endl;
                        if(dockSignal[i] == DOCK_NEWITEM) {
                            targetDock = i;
                            while(true) {
                                 color = follow();
                                 if(color != dockColor[i]) forward(STEP); // Small forward step
                                 else {
                                    forward(STEP);
                                    setSpeed(0, 0);
                                    extApi_sleepMs(500);
                                    state = 2;
                                    cout << "Ready to pick box at dock " << targetDock << "!" << endl;
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
                getNewBoxSignal();
                simxSetObjectParent(clientID, (simxInt) newBoxSignal[targetDock], (simxInt) robotHandle, true, simx_opmode_oneshot_wait);
                dockSignal[targetDock] = DOCK_EMPTY;
                setDockSignal();
                cout << "DockSignal: " << dockSignal[targetDock] << endl;
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
                            if(i != targetDock && dockSignal[i] != DOCK_FULL) {
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
                    simxSetObjectParent(clientID, (simxInt) newBoxSignal[!targetDock], -1, true, simx_opmode_oneshot_wait);
                    dockSignal[targetDock] = DOCK_FULL;
                    // dockSignal[!targetDock] = DOCK_EMPTY;
                    setDockSignal();                    
                    state = 0; // Next state: wait for instruction
                    break;
                }
                break;
        }
    }
}
