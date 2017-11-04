#include "linefollow.h"
#include "diffdrive.h"
#include <cmath>

#define BLACK 0
#define RED 1
#define GREEN 2
#define BLUE 3
#define YELLOW 4
#define OTHER 5

#define MAX_SPEED 0.12 // Pioneer 3-DX
#define MAX_ROTATION 0.6 // Pioneer 3-DX
#define INC 0.1

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
            if(colors[i] != BLACK && colors[i] != OTHER) return colors[i];
        }
        // No color flags found: follow line
        if(colors[0] == 0) { // Left sensor sees black
            if(fabs(twist[1]) <= MAX_ROTATION - INC) twist[1] += INC; // Turn left
        }
        else if(colors[2] == 0) { // Right sensor sees black
            if(fabs(twist[1]) <= MAX_ROTATION - INC) twist[1] -= INC; // Turn right
        }
        else twist[1] = 0;
        // Assign speed to motors
        setSpeed(twist[0], twist[1]);
    }
}

int LineFollow::followReverse() {
    int* colors = new int[3];
    float twist[] = {- MAX_SPEED/2, 0};
    while(true) {
         // Check if some color flag was found
         colors = getColors();
         for(int i = 0; i < 3; i++) {
             if(colors[i] != BLACK && colors[i] != OTHER) return colors[i];
         }
         // No color flags found: follow line in reverse
         if(colors[0] == 0) { // Left sensor sees black
             if(fabs(twist[1]) <= MAX_ROTATION - INC) twist[1] -= INC; // Turn left in reverse
         }
         else if(colors[2] == 0) { // Right sensor sees black
             if(fabs(twist[1]) <= MAX_ROTATION - INC) twist[1] += INC; // Turn right in reverse
         }
         else twist[1] = 0;
         // Assign speed to motors
         setSpeed(twist[0], twist[1]);
    }
}

void LineFollow::followUntilDistance(float distance) {
    float twist[] = {MAX_SPEED/2, 0};
    while(true) {
        readUSensor();
        if(uSensorDistance[3] < distance || uSensorDistance[4] < distance) {
            setSpeed(0, 0);
        }
        else {
            int* colors = new int[3];
            colors = getColors();
            if(colors[0] == BLACK) { // Left sensor sees black
                if(fabs(twist[1]) <= MAX_SPEED - INC) twist[1] += INC; // Turn left
            }
            else if(colors[2] == BLACK) { // Right sensor sees black
                if(fabs(twist[1]) <= MAX_SPEED - INC) twist[1] -= INC; // Turn right
            }
            else twist[1] = 0;
            // Assign speed to motors
            setSpeed(twist[0], twist[1]);
        }
    }
}

void LineFollow::spin(float angle) {
    float initialPos[2], tempPos[2];
    // Read initial position
    for(int i = 0; i < 2; i++) {
        simxGetJointPosition(clientID, (simxInt) motorHandle[i], (simxFloat*) &initialPos[i], simx_opmode_buffer);
    }
    // Calculate absolute value of position difference
    float deltaPos = fabs(angle2wheelPos(angle));
    // Define rotation direction
    if(angle > 0) setSpeed(0, MAX_ROTATION);
    else setSpeed(0, -MAX_ROTATION);
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

void LineFollow::forward(float displacement) {
    float initialPos[2], tempPos[2];
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