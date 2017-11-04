#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

/* States:
 * 0 = Start
 * 1 = Wait for instruction
 * 2 = Pick box
 * 3 = Place box
 */

#include "linefollow.h"

class StateMachine: public LineFollow {
private:
    int state;
    // Full robot handle
    int robotHandle;
    // Dock signal
    int dockSignal[2];
    // Signal to store the handle of the box associated with each dock
    int dockBoxHandleSignal[2];
public:
    StateMachine();
    ~StateMachine();
    void getDockSignal();
    void setDockSignal();
    void getDockBoxHandleSignal();
    void setDockBoxHandleSignal();    
    void run();
};

#endif // STATEMACHINE_H_