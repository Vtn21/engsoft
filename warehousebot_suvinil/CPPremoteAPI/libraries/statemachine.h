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
    int newBoxSignal[2];
    // Color of robot, and box (dock0L, dock0U, dock1L, dock1U), respectively
    int stColor[5];
public:
    StateMachine();
    ~StateMachine();
    void getDockSignal();
    void setDockSignal();
    // void getNewBoxSignal();
    // void setNewBoxSignal();
    void run();
    void setColor(void);
};

#endif // STATEMACHINE_H_
