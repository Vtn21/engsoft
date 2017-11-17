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

int LineFollow::followReverse() {
    int* colors = new int[3];
    float twist[] = {- MAX_SPEED/2, 0};
    while(true) {
         // Check if some color flag was found
         colors = getColors();
         for(int i = 0; i < 3; i++) {
             if(colors[i] != BLACK && colors[i] != WHITE) return colors[i];
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
         extApi_sleepMs(5);
    }
}

int LineFollow::reverse() {
    int* colors = new int[3];
    float twist[] = {-MAX_SPEED, 0};
    setSpeed(twist[0], twist[1]);
    while(true) {
        // Check if some color flag was found
        colors = getColors();
        if(colors[1] != 0) {
            setSpeed(0, 0);
            return colors[1];
        }
    }
}

void LineFollow::followUntilDistance(float distance) {
    float twist[] = {MAX_SPEED, 0};
    while(true) {
        readUSensor();
        if(uSensorDistance[3] < distance || uSensorDistance[4] < distance) {
            setSpeed(0, 0);
            return;
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
        extApi_sleepMs(5);
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

void LineFollow::spinUntilLine(int direction) {
    setSpeed(0, direction * MAX_ROTATION);
    int* colors = new int[3];
    do {
        colors = getColors();
    } while(colors[1] != BLACK);
    setSpeed(0, 0);
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