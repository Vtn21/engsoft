#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include "linefollow.h"

class StateMachine: public LineFollow {
private:
    int state;
    // Full robot handle
    int robotHandle;
    // Dock signals
    int loadSignal[2];
    int unloadSignal[2];
    // Color of robot, and box (dock0L, dock0U, dock1L, dock1U), respectively
    int colorSignal[5];
public:
    StateMachine();
    ~StateMachine();
    void getDockSignal();
    void setDockSignal();
    void getColorSignal();
    void setColorSignal();
    void run();
};

#endif // STATEMACHINE_H_
