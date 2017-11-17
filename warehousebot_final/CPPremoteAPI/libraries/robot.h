#ifndef ROBOT_H_
#define ROBOT_H_

extern "C" {
	#include <extApi.h>
}
  
#include <iostream>
#include <string>

#define _USE_MATH_DEFINES
#include <cmath>

#define BLACK 0
#define RED 1
#define GREEN 2
#define BLUE 3
#define WHITE 4
#define YELLOW 5

using namespace std;

class Robot {
private:
    // Server parameters
    string serverIP;
    int serverPort;
    // Ultrasonic sensors
    string uSensorName[16];
    int uSensorHandle[16];
    // Vision sensors
    string vSensorName[3];
    int vSensorHandle[3];
    float vSensorIntensity[3][3];
protected:
    // Server parameters
    int clientID;
    // Motors
    int motorHandle[2];
    // Ultrasonic sensors
    float uSensorDistance[16];
    // Methods
    Robot();
    ~Robot();
    bool isActive();
    void readUSensor();
    void readVSensor();
    int* getColors();
    void setSpeed(float linear, float angular);
};

#endif // ROBOT_H_
