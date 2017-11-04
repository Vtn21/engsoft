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
    void followUntilDistance(float distance);
    void spin(float angle);
    void forward(float displacement);
};

#endif // LINEFOLLOW_H_