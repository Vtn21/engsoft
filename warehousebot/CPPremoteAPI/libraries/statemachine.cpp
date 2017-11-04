#include "statemachine.h"
#include "dock.h"

#define STEP 0.2
#define DOCK_DISTANCE 0.4

StateMachine::StateMachine(): LineFollow() {
    state = 0; 
    // Connect to the full robot
    if(simxGetObjectHandle(clientID, (const simxChar*) "Pioneer_p3dx", (simxInt *) &robotHandle, (simxInt) simx_opmode_oneshot_wait) != simx_return_ok)
        cout << "Pioneer_p3dx handle not found!" << endl;  
    else
        cout << "Connected to Pioneer_p3dx!" << endl;
}

StateMachine::~StateMachine();

bool StateMachine::getDockSignal() {
    for(int i = 0; i < 2; i++) {
        if(simxGetIntegerSignal(clientID, (const simxChar*) ("dockSignal" + to_string(i)).c_str(), (simxInt*) &dockSignal[i], simx_opmode_buffer) != simx_return_ok) return false;
    } 
    return true;   
}

void StateMachine::setDockSignal() {
    for(int i = 0; i < 2; i++) {
        simxSetIntegerSignal(clientID, (const simxChar*) ("dockSignal" + to_string(i)).c_str(), (simxInt) dockSignal[i], simx_opmode_oneshot);
    }
}

bool StateMachine::getDockBoxHandleSignal() {
    for(int i = 0; i < 2; i++) {
        if(simxGetIntegerSignal(clientID, (const simxChar*) ("dockBoxHandleSignal" + to_string(i)).c_str(), (simxInt*) &dockBoxHandleSignal[i], simx_opmode_buffer) != simx_return_ok) return false;
    } 
    return true;   
}

void StateMachine::setDockBoxHandleSignal() {
    for(int i = 0; i < 2; i++) {
        simxSetIntegerSignal(clientID, (const simxChar*) ("dockBoxHandleSignal" + to_string(i)).c_str(), (simxInt) dockBoxHandleSignal[i], simx_opmode_oneshot);
    }
}

bool StateMachine::run() {
    int color;
    int targetDock;
    switch(state) {
        case 0: // Start
            color = follow(); // Follow line until green mark is detected
            if(color != GREEN) {
                cout << "Start simulation with robot inside green dock" << endl;
                return false;
            }
            else {
                if(forward(STEP)) { // Small forward step
                    if(spin(- M_PI / 2)) { // 90 degree clockwise turn
                        state = 1;
                        break;
                    }           
                    else return false;         
                }
                else return false;
            }
        case 1: // Wait for instruction
            while(isActive()) {
                if(!getDockSignal()) return false;
                else {
                    for(int i = 0; i < 2; i++) {
                        if(dockSignal[i] == DOCK_NEWITEM) {
                            targetDock = i;
                            do {
                                color = follow();
                            } while(color != dockColor[i]);
                            if(forward(STEP)) { // Small forward step
                                if(spin(- M_PI / 2)) { // 90 degree clockwise turn
                                    state = 2; // Next state: pick the box
                                    break;
                                }
                                else return false;
                            }
                            else return false;
                        }
                    }
                }
            }
        case 2: // Pick box
            followUntilDistance(DOCK_DISTANCE);
            if(!getDockBoxHandleSignal()) {
                cerr << "Unable to connect to the box to be collected" << endl;
                return false;
            }
            else {
                if(simxSetObjectParent(clientID, (simxInt) dockBoxHandleSignal[targetDock], robotHandle, false, simx_opmode_blocking) == simx_return_ok) {
                    cout << "Successfully picked box at dock #" << targetDock << endl;
                    dockSignal[targetDock] = DOCK_EMPTY;
                    setDockSignal();
                }
                else {
                    cerr << "Unable to pick box" << endl;
                    return false;
                }
            }
            followReverse(); // Return to main path
            if(forward(-STEP)) { // Small backwards step
                if(spin(- M_PI / 2)) { // 90 degree counterclockwise turn
                    state = 3; // Next state: place the recently picked box
                    break;
                }
            }
        case 3: // Place box
            while(isActive()) {
                if(!getDockSignal()) return false;
                else {
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
                    if(forward(STEP)) { // Small forward step
                        if(spin(- M_PI / 2)) { // 90 degree clockwise turn
                            followUntilDistance(DOCK_DISTANCE);
                            if(simxSetObjectParent(clientID, (simxInt) dockBoxHandleSignal[abs(targetDock - 1)], -1, true, simx_opmode_blocking) == simx_return_ok) {
                                cout << "Successfully placed box at dock #" << targetDock << endl;
                                dockSignal[targetDock] = DOCK_FULL;
                                setDockSignal();
                            }
                            else {
                                cerr << "Unable to place box" << endl;
                                return false;
                            }
                            followReverse(); // Return to main path
                            if(forward(-STEP)) { // Small backwards step
                                if(spin(- M_PI / 2)) { // 90 degree counterclockwise turn
                                    state = 1; // Next state: wait for instruction
                                    break;
                                }
                            }
                        }
                        else return false;
                    }
                    else return false;
                }
            }
    }
}