#include "linefollow.h"
#include "diffdrive.h"
#include <cmath>

#define MAX_SPEED 1.2 // Pioneer 3-DX
#define MAX_ROTATION 3 // Pioneer 3-DX
#define INC 0.01

LineFollow::LineFollow(): Robot() {
    float initialPos[2];
    for(int i = 0; i < 2; i++) {
        simxGetJointPosition(clientID, (simxInt) motorHandle[i], (simxFloat*) &initialPos[i], simx_opmode_streaming);
    }    
}

LineFollow::~LineFollow();

uint16_t LineFollow::follow() {
    uint16_t colors[3];
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
        if(!setSpeed(twist[0], twist[1])) return -1;
    }
}

uint16_t LineFollow::followReverse() {
    uint16_t colors[3];
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
         if(!setSpeed(twist[0], twist[1])) return -1;
    }
}

bool LineFollow::followUntilDistance(float distance) {
    while(true) {
        readUSensor();
        if(uSensorDistance[3] < distance || uSensorDistance[4] < distance) {
            if(!setSpeed(0, 0) return false;
            else return true;
        }
        else {
            uint16_t colors[3];
            colors = getColors();
            if(colors[0] == BLACK) { // Left sensor sees black
                if(fabs(twist) <= MAX_SPEED - INC) twist[1] += INC; // Turn left
            }
            else if(colors[2] == BLACK) { // Right sensor sees black
                if(fabs(twist) <= MAX_SPEED - INC) twist[1] -= INC; // Turn right
            }
            else twist[1] = 0;
            // Assign speed to motors
            if(!setSpeed(twist[0], twist[1])) return false;
        }
    }
}

bool LineFollow::spin(float angle) {
    float initialPos[2];
    for(int i = 0; i < 2; i++) {
        simxGetJointPosition(clientID, (simxInt) motorHandle[i], (simxFloat*) &initialPos[i], simx_opmode_buffer);
    }
    float deltaPos = angle2wheelPos(angle);
    if(!setSpeed(0, 0)) return false; // Stop robot before spinning
    if(simxSetJointTargetPosition(clientID, motorHandle[0], (simxFloat*) initialPos[0] - deltaPos, simx_opmode_oneshot) != simx_return_ok) return false;
    if(simxSetJointTargetPosition(clientID, motorHandle[1], (simxFloat*) initialPos[1] + deltaPos, simx_opmode_oneshot) != simx_return_ok) return false;
    return true;
}

bool LineFollow::forward(float displacement) {
    float initialPos[2];
    for(int i = 0; i < 2; i++) {
        simxGetJointPosition(clientID, (simxInt) motorHandle[i], (simxFloat*) &initialPos[i], simx_opmode_buffer);
    }
    float deltaPos = displacement2wheelPos(displacement);
    if(!setSpeed(0, 0)) return false; // Stop robot before spinning
    for(int i = 0; i < 2; i++) {
        if(simxSetJointTargetPosition(clientID, motorHandle[i], (simxFloat*) initialPos[i] + deltaPos, simx_opmode_oneshot) != simx_return_ok) return false;
    }
    return true;
}