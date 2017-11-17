#ifndef LINEFOLLOW_H_
#define LINEFOLLOW_H_

#include "robot.h"

#define BLACK 0
#define RED 1
#define GREEN 2
#define BLUE 3
#define WHITE 4
#define YELLOW 5

#define MAX_SPEED 0.2 // Pioneer 3-DX
#define MAX_ROTATION 0.3 // Pioneer 3-DX
#define INC 0.005
#define STEP 0.2

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
