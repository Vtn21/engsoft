#include "robot.h"
#include "diffdrive.h"

Robot::Robot() {
    // Assign default values to server parameters
    serverIP = "127.0.0.1";
    serverPort = 19999;
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
        // Connect to ultrasonic sensors
        for(int i = 0; i < 16; i++) {
            uSensorName[i] = "Pioneer_p3dx_ultrasonicSensor" + to_string(i + 1);
            if(simxGetObjectHandle(clientID, (const simxChar*) uSensorName[i].c_str(), (simxInt*) &uSensorHandle[i], (simxInt) simx_opmode_oneshot_wait) != simx_return_ok)
                cout << uSensorName[i] << " handle not found!" << endl;
            else {
                cout << "Connected to " << uSensorName[i] << "!" << endl;
                simxReadProximitySensor(clientID, uSensorHandle[i], NULL, NULL, NULL, NULL, simx_opmode_streaming);
            }
        }
        // Connect to vision sensors
        for(int i = 0; i < 3; i++) {
            vSensorName[i] = "Pioneer_p3dx_visionSensor" + to_string(i + 1);
            if(simxGetObjectHandle(clientID, (const simxChar*) vSensorName[i].c_str(), (simxInt*) &vSensorHandle[i], (simxInt) simx_opmode_oneshot_wait) != simx_return_ok)
                cout << vSensorName[i] << " handle not found!" << endl;
            else {
                cout << "Connected to " << vSensorName[i] << "!" << endl;
                simxReadVisionSensor(clientID, vSensorHandle[i], NULL, NULL, NULL, simx_opmode_streaming);
            }
        }
        simxGetFloatSignal(clientID, "batteryLevel", NULL, simx_opmode_streaming);
    }
    else {
        // Connection problems
        cout << "Unable to connect to server!" << endl;
    }
}

Robot::~Robot() {
    // Close connection to server
    if(isActive()) {
        simxFinish(clientID);
        cout << "Connection closed!" << endl;
    }
}

bool Robot::isActive() {
    if(simxGetConnectionId(clientID) != -1) return true;
    else return false;
}

void Robot::readUSensor() {
    // Read all 16 ultrasonic sensors
    for(int i = 0; i < 16; i++) {
        simxUChar state;
        simxFloat coord[3];
        simxReadProximitySensor(clientID, (simxInt) uSensorHandle[i], &state, coord, NULL, NULL, simx_opmode_streaming);
        uSensorDistance[i] = (float) coord[2]; // Update distance related to each sensor
    }
}

void Robot::readVSensor() {
    // Read all 3 vision sensors
    simxFloat* values;
    simxInt* count;
    for(int i = 0; i < 3; i++) {
        simxReadVisionSensor(clientID, vSensorHandle[i], NULL, &values, &count, simx_opmode_buffer);
        vSensorIntensity[i][0] = values[11]; // R
        vSensorIntensity[i][1] = values[12]; // G
        vSensorIntensity[i][2] = values[13]; // B
    }
}

int* Robot::getColors() {
    // Return a 3-element array with the color detected by each sensor
    // Update vision sensor readings
    readVSensor();
    // Translate from RGB intensity to color codes
    static int colors[3];
    for(int i = 0; i < 3; i++) {
        if(vSensorIntensity[i][0] < 0.1) { // R < 0.1
            if(vSensorIntensity[i][1] < 0.1) { // G < 0.1
                if(vSensorIntensity[i][2] < 0.1) { // B < 0.1
                    colors[i] = BLACK;
                }
                else if(vSensorIntensity[i][2] > 0.9) { // B > 0.9
                    colors[i] = BLUE;
                }
            }
            else if(vSensorIntensity[i][1] > 0.9) { // G > 0.9
                if(vSensorIntensity[i][2] < 0.1) { // B < 0.1
                    colors[i] = GREEN;
                }
            }
        }
        else if(vSensorIntensity[i][0] > 0.9) { // R > 0.9
            if(vSensorIntensity[i][1] < 0.1 && vSensorIntensity[i][2] < 0.1) { // G < 0.1 && B < 0.1
                colors[i] = RED;
            }
            else if(vSensorIntensity[i][1] > 0.9 && vSensorIntensity[i][2] < 0.1) { // G > 0.9 && B < 0.1
                colors[i] = YELLOW;
            }
        }
        else colors[i] = WHITE;
    }
    return colors;
}

void Robot::setSpeed(float linear, float angular) {
    float* jointSpeed = new float[2];
    jointSpeed = twist2jointSpeed(linear, angular);
    for(int i = 0; i < 2; i++) {
        simxSetJointTargetVelocity(clientID, motorHandle[i], (simxFloat) jointSpeed[i], simx_opmode_streaming);
    }
    float motorLoad = fabs(jointSpeed[0]) + fabs(jointSpeed[1]);
    simxSetFloatSignal(clientID, "motorLoad", (simxFloat) motorLoad, simx_opmode_oneshot);
}

float Robot::getBatteryLevel()
{
    float ret;
    simxGetFloatSignal(clientID, "batteryLevel", (simxFloat *) &ret, simx_opmode_buffer);
    return ret;
}
