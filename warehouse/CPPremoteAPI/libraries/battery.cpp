#include <battery.h>

Battery::Battery()
{
    level = 100.0;

    // Assign default values to server parameters
    serverIP = "127.0.0.1";
    serverPort = 20001;
    // Start communication
    clientID = simxStart((simxChar*) serverIP.c_str(), serverPort, true, true, 2000, 5);
    if(clientID != -1) {
        // Connection OK
        cout << "Server connected!" << endl;
        // Connect to motors
        if(simxGetObjectHandle(clientID, (const simxChar*) "Pioneer_p3dx_leftMotor", (simxInt *) &motorHandle[0], (simxInt) simx_opmode_oneshot_wait) != simx_return_ok)
            cout << "Pioneer_p3dx_leftMotor handle not found!" << endl;
        else
            cout << "Connected to Pioneer_p3dx_leftMotor!" << endl;
        if(simxGetObjectHandle(clientID, (const simxChar*) "Pioneer_p3dx_rightMotor", (simxInt *) &motorHandle[1], (simxInt) simx_opmode_oneshot_wait) != simx_return_ok)
            cout << "Pioneer_p3dx_rightMotor handle not found!" << endl;
        else
            cout << "Connected to Pioneer_p3dx_rightMotor!" << std::endl;

        simxGetFloatSignal(clientID, "motorLoad", NULL, simx_opmode_streaming);
        simxGetFloatSignal(clientID, "batteryLevel", NULL, simx_opmode_streaming);
    } else
    {
        // Connection problems
        cout << "Unable to connect to server!" << endl;
    }
}

Battery::~Battery() {
    // Close connection to server
    if(isActive()) {
        simxFinish(clientID);
        cout << "Connection closed!" << endl;
    }
}

bool Battery::isActive() {
    if(simxGetConnectionId(clientID) != -1) return true;
    else return false;
}

float Battery::totalMotorLoad() {
    float ret;
    simxGetFloatSignal(clientID, "motorLoad", (simxFloat *) &ret, simx_opmode_buffer);
    return ret;
}

void Battery::updateBatteryLevelSignal() {
    simxGetFloatSignal(clientID, "batteryLevel", (simxFloat *) &level, simx_opmode_buffer);
    float motorLoad = totalMotorLoad();
    level -= motorLoad * DISCHARGE_WEIGHT;
    simxSetFloatSignal(clientID, "batteryLevel", (simxFloat) level, simx_opmode_oneshot);
}

float Battery::getBatteryLevel() {
    return level;
}
