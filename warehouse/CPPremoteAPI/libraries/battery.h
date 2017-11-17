#ifndef BATTERY_H_
#define BATTERY_H_

extern "C" {
	#include <extApi.h>
}

#include <iostream>
#include <string>

#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

#define BATTERY_CRITICAL 15.0
#define DISCHARGE_WEIGHT 0.002

class Battery
{
private:
	float level;
	// Server parameters
    string serverIP;
    int serverPort;
    int clientID;
    // Motor handles
    int motorHandle[2];
	// Motor load getter method
	float totalMotorLoad();
public:
	Battery();
	~Battery();
	bool isActive();
	void updateBatteryLevelSignal();
	float getBatteryLevel();
};

#endif
