#include "linefollow.h"
#include "diffdrive.h"
#include <cmath>

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

LineFollow::LineFollow(): Robot() {
    float initialPos[2];
    for(int i = 0; i < 2; i++) {
        simxGetJointPosition(clientID, (simxInt) motorHandle[i], (simxFloat*) &initialPos[i], simx_opmode_streaming);
    }    
}

LineFollow::~LineFollow() {}

int LineFollow::follow() {
    int* colors = new int[3];
    float twist[] = {MAX_SPEED, 0};
    while(true) {
        // Check if some color flag was found
        colors = getColors();
        for(int i = 0; i < 3; i++) {
            if(colors[i] != BLACK && colors[i] != WHITE) return colors[i];
        }
        // No color flags found: follow line
        if(colors[0] == 0) { // Left sensor sees black
            twist[0] = MAX_SPEED;
            if(fabs(twist[1]) <= MAX_ROTATION - INC) twist[1] += INC; // Turn left
        }
        else if(colors[2] == 0) { // Right sensor sees black
            twist[0] = MAX_SPEED;
            if(fabs(twist[1]) <= MAX_ROTATION - INC) twist[1] -= INC; // Turn right
        }
        else if(colors[1] == 0) { // Middle sensor sees black
            twist[0] = MAX_SPEED;
            twist[1] = 0; // Go forward
        }
        else { // No sensor sees black: line lost
            twist[0] = -MAX_SPEED;
            twist[1] = 0; // Go backwards
        }
        // Assign speed to motors
        setSpeed(twist[0], twist[1]);
        extApi_sleepMs(5);
    }
}

void LineFollow::forward(float displacement) {
    float initialPos[2], tempPos[2];
    for(int i = 0; i < 2; i++) {
        simxSetJointPosition(clientID, (simxInt) motorHandle[i], (simxFloat) 0, simx_opmode_streaming);
    }
    // Read initial position
    for(int i = 0; i < 2; i++) {
        simxGetJointPosition(clientID, (simxInt) motorHandle[i], (simxFloat*) &initialPos[i], simx_opmode_buffer);
    }
    // Calculate absolute value of position difference
    float deltaPos = fabs(displacement2wheelPos(displacement));
    // Define rotation direction
    if(displacement > 0) setSpeed(MAX_SPEED, 0);
    else setSpeed(-MAX_SPEED, 0);
    // Poll position until deltaPos is satisfied
    bool stop = false;
    do {
        for(int i = 0; i < 2; i++) {
            simxGetJointPosition(clientID, (simxInt) motorHandle[i], (simxFloat*) &tempPos[i], simx_opmode_buffer);
            if(fabs(tempPos[i] - initialPos[i]) >= deltaPos) stop = true;
        }
    } while(!stop);
    // Stop robot
    setSpeed(0, 0);
}

void LineFollow::followUntilColor(int targetColor) {
    int tempColor;
    do {
        tempColor = follow();
        forward(STEP);
    } while(tempColor != targetColor);
    setSpeed(0, 0);
}