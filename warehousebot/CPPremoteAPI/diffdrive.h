#ifndef DIFFDRIVE_H_
#define DIFFDRIVE_H_

float[] twist2jointSpeed(float linear, float angular);

float angle2wheelPos(float angle); // Holonomic spin

#endif // DIFFDRIVE_H_