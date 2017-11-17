#ifndef LINEFOLLOW_H_
#define LINEFOLLOW_H_

#include "robot.h"

class LineFollow: public Robot {
protected:
    // Methods
    LineFollow();
    ~LineFollow();
    int follow();
    void forward(float displacement);
    void followUntilColor(int color);
};

#endif // LINEFOLLOW_H_