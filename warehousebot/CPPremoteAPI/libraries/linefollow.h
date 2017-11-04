#ifndef LINEFOLLOW_H_
#define LINEFOLLOW_H_

#include "robot.h"

class LineFollow: public Robot {
protected:
    // Methods
    LineFollow();
    ~LineFollow();
    int follow();
    int followReverse();
    bool followUntilDistance(float distance);
    bool spin(float angle);
    bool forward(float displacement);
};

#endif // LINEFOLLOW_H_