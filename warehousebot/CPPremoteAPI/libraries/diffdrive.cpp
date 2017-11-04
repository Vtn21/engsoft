#include "diffdrive.h"

float axleTrack = 0.381; // Pioneer 3-DX
float wheelRadius = 0.0975; // Pioneer 3-DX

float* twist2jointSpeed(float linear, float angular) {
    static float jointSpeed[2];
    jointSpeed[0] = (linear - axleTrack * angular / 2) / wheelRadius; // Left wheel angular speed
    jointSpeed[1] = (linear + axleTrack * angular / 2) / wheelRadius; // Right wheel angular speed
    return jointSpeed;
}

float angle2wheelPos(float angle) { // Holonomic spin
    return (angle * axleTrack) / (2 * wheelRadius);
}

float displacement2wheelPos(float displacement) { // Forward displacement
    return displacement / wheelRadius;
}