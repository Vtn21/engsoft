#ifndef DIFFDRIVE_H_
#define DIFFDRIVE_H_

float* twist2jointSpeed(float linear, float angular);

float angle2wheelPos(float angle); // Holonomic spin

float displacement2wheelPos(float displacement); // Forward displacement

#endif // DIFFDRIVE_H_