#include "statemachine.h"
#include "dock.h"

#define BLACK 0
#define RED 1
#define GREEN 2
#define BLUE 3
#define YELLOW 4
#define OTHER 5

#define STEP 0.2
#define DOCK_DISTANCE 0.4

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
        simxGetIntegerSignal(clientID, (const simxChar*) ("dockSignal" + to_string(i)).c_str(), (simxInt*) &dockSignal[i], simx_opmode_buffer);
    }  
}

void StateMachine::setDockSignal() {
    for(int i = 0; i < 2; i++) {
        simxSetIntegerSignal(clientID, (const simxChar*) ("dockSignal" + to_string(i)).c_str(), (simxInt) dockSignal[i], simx_opmode_oneshot);
    }
}

void StateMachine::getDockBoxHandleSignal() {
    for(int i = 0; i < 2; i++) {
        simxGetIntegerSignal(clientID, (const simxChar*) ("dockBoxHandleSignal" + to_string(i)).c_str(), (simxInt*) &dockBoxHandleSignal[i], simx_opmode_buffer);
    } 
}

void StateMachine::setDockBoxHandleSignal() {
    for(int i = 0; i < 2; i++) {
        simxSetIntegerSignal(clientID, (const simxChar*) ("dockBoxHandleSignal" + to_string(i)).c_str(), (simxInt) dockBoxHandleSignal[i], simx_opmode_oneshot);
    }
}

void StateMachine::run() {
    int color;
    int targetDock;
    while(isActive()) {
        switch(state) {
            case 0: // Start
                color = follow(); // Follow line until green mark is detected
                if(color != GREEN) {
                    cout << "Start simulation with robot inside green dock" << endl;
                }
                else {
                    forward(STEP); // Small forward step
                    spin(- M_PI / 2); // 90 degree clockwise turn
                    state = 1;
                    break;
                }
            case 1: // Wait for instruction
                while(isActive()) {
                    getDockSignal();
                    cout << "Checking docks..." << endl;
                    for(int i = 0; i < 2; i++) {
                        if(dockSignal[i] == DOCK_NEWITEM) {
                            targetDock = i;
                            do {
                                 color = follow();
                            } while(color != dockColor[i]);
                            forward(STEP); // Small forward step
                            spin(- M_PI / 2); // 90 degree clockwise turn
                            state = 2; // Next state: pick the box
                            break;
                        }
                    }
                }
            case 2: // Pick box
                followUntilDistance(DOCK_DISTANCE);
                getDockBoxHandleSignal();
                simxSetObjectParent(clientID, (simxInt) dockBoxHandleSignal[targetDock], robotHandle, false, simx_opmode_oneshot_wait);
                dockSignal[targetDock] = DOCK_EMPTY;
                setDockSignal();
                followReverse(); // Return to main path
                forward(-STEP); // Small backwards step
                spin(- M_PI / 2); // 90 degree counterclockwise turn
                state = 3; // Next state: place the recently picked box
                break;
            case 3: // Place box
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
                            }
                        }
                    } while(flag);
                    // Go to the other dock
                    do {
                        color = follow();
                    } while(color != dockColor[targetDock]);
                    forward(STEP); // Small forward step
                    spin(- M_PI / 2); // 90 degree clockwise turn
                    followUntilDistance(DOCK_DISTANCE);
                    simxSetObjectParent(clientID, (simxInt) dockBoxHandleSignal[abs(targetDock - 1)], -1, true, simx_opmode_oneshot_wait);
                    dockSignal[targetDock] = DOCK_FULL;
                    setDockSignal();
                    followReverse(); // Return to main path
                    forward(-STEP); // Small backwards step
                    spin(- M_PI / 2); // 90 degree counterclockwise turn
                    state = 1; // Next state: wait for instruction
                    break;
                }
        }
    }
}