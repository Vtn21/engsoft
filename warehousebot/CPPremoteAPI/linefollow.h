#ifndef LINEFOLLOW_H_
#define LINEFOLLOW_H_

#include "robot.h"

class LineFollow: public Robot {
public:
    LineFollow();
    ~LineFollow();
    uint16_t follow();
    uint16_t follow_reverse();
    bool followUntilDistance(float distance);
    bool LineFollow::spin(float angle);
}

#endif // LINEFOLLOW_H_