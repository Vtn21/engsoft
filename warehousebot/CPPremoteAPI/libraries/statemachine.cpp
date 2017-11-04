#include "statemachine.h"
#include "dock.h"

#define STEP 0.2
#define DOCK_DISTANCE 0.4

StateMachine::StateMachine(): LineFollow() {
    state = 0; 
}

StateMachine::~StateMachine();

bool StateMachine::run() {
    uint16_t color;
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
                            do {
                                color = follow();
                            } while(color != dockColor[i]);
                            if(forward(STEP)) { // Small forward step
                                if(spin(- M_PI / 2)) { // 90 degree clockwise turn
                                    state = 2;
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
            
    }
}