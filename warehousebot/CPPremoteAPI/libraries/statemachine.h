#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

/* States:
 * 0 = Start
 * 1 = Wait for instruction
 * 2 = Pick box
 */

#include "linefollow.h"

class StateMachine: public LineFollow {
private:
    uint16_t state;
public:
    StateMachine();
    ~StateMachine();
    bool run();
};

#endif // STATEMACHINE_H_