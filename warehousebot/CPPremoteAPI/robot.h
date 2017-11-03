#ifndef ROBOT_H_
#define ROBOT_H_

extern "C" {
	#include "remoteApi/extApi.h"
}
  
#include <iostream>
#include <string>

#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

class Robot {
private:
    // Server parameters
    string serverIP;
    int serverPort;
    int clientID;
    // Motors
    int motorHandle[2];
    // Ultrasonic sensors
    string uSensorName[16];
    int uSensorHandle[16];
    // Vision sensors
    string vSensorName[3];
    int vSensorHandle[3];
    float vSensorIntensity[3][3];
protected:
    // Ultrasonic sensors
    float uSensorDistance[16];
public:
    Robot();
    ~Robot();
    bool readUSensor();
    bool readVSensor();
    uint16_t[] getColors();
    bool setSpeed(float linear, float angular);
};

#endif // ROBOT_H_
