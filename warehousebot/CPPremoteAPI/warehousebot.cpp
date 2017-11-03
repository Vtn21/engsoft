//============================================================================
// Name        : warehousebot.cpp
// Author      : Victor T. Noppeney
// Version     :
// Copyright   : All rights reserved
// Description : Warehouse robot controller (autonomous)
//============================================================================

extern "C" {
	#include "remoteApi/extApi.h"
}
  
#include <iostream>
#include <string>

#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

int main(int argc, char **argv) {
    // Server initialization
    string serverIP = "127.0.0.1";
    int serverPort = 19999;
    // Motors
    int motorHandle[2];
    float motorSpeed[2];
    // Ultrasonic sensors
    string uSensorName[16];
    int uSensorHandle[16];
    float uSensorDistance[16];
    // Vision sensors
    string vSensorName[3];
    int vSensorHandle[3];
    float vSensorIntensity[3][3];
    // Start communication
    int clientID = simxStart((simxChar*) serverIP.c_str(), serverPort, true, true, 2000, 5);
    if(clientID != -1) {
        // Connection OK
        cout << "Server connected!" << endl;
        // Connect to motors
        if(simxGetObjectHandle(clientID, (const simxChar*) "Pioneer_p3dx_rightMotor", (simxInt *) &rightMotorHandle, (simxInt) simx_opmode_oneshot_wait) != simx_return_ok)
            cout << "Pioneer_p3dx_rightMotor handle not found!" << endl;  
        else
            cout << "Connected to Pioneer_p3dx_rightMotor!" << std::endl;
        if(simxGetObjectHandle(clientID, (const simxChar*) "Pioneer_p3dx_leftMotor", (simxInt *) &leftMotorHandle, (simxInt) simx_opmode_oneshot_wait) != simx_return_ok)
            cout << "Pioneer_p3dx_leftMotor handle not found!" << endl;  
        else
            cout << "Connected to Pioneer_p3dx_leftMotor!" << endl;
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
    }
    else {
        // Connection problems
        cout << "Unable to connect to server!" << endl;
    }
	

	  
// 		  // Inicializa��o dos sensores
  
// 		  if(simxGetObjectHandle(clientID, (const simxChar*) "sensingNose", (simxInt *) &noseSensorHandle, (simxInt) simx_opmode_oneshot_wait) != simx_return_ok)
// 			  cout << "Handle do sensor do nariz nao encontrado!" << std::endl;
// 		  else
// 		  {
// 			  cout << "Conectado ao sensor do nariz!" << std::endl;
// 			  simxReadProximitySensor(clientID, noseSensorHandle, NULL, NULL, NULL, NULL, simx_opmode_streaming);
// 		  }
  
// 		  if(simxGetObjectHandle(clientID, (const simxChar*) "leftSensor", (simxInt *) &leftSensorHandle, (simxInt) simx_opmode_oneshot_wait) != simx_return_ok)
// 			  cout << "Handle do sensor esquerdo nao encontrado!" << std::endl;
// 		  else
// 		  {
// 			  cout << "Conectado ao sensor esquerdo!" << std::endl;
// 			  simxReadVisionSensor(clientID, leftSensorHandle, NULL, NULL, NULL, simx_opmode_streaming);
// 		  }
  
// 		  if(simxGetObjectHandle(clientID, (const simxChar*) "middleSensor", (simxInt *) &middleSensorHandle, (simxInt) simx_opmode_oneshot_wait) != simx_return_ok)
// 			  cout << "Handle do sensor central nao encontrado!" << std::endl;
// 		  else
// 		  {
// 			  cout << "Conectado ao sensor central!" << std::endl;
// 			  simxReadVisionSensor(clientID, middleSensorHandle, NULL, NULL, NULL, simx_opmode_streaming);
// 		  }
  
// 		  if(simxGetObjectHandle(clientID, (const simxChar*) "rightSensor", (simxInt *) &rightSensorHandle, (simxInt) simx_opmode_oneshot_wait) != simx_return_ok)
// 			  cout << "Handle do sensor direito nao encontrado!" << std::endl;
// 		  else
// 		  {
// 			  cout << "Conectado ao sensor direito!" << std::endl;
// 			  simxReadVisionSensor(clientID, rightSensorHandle, NULL, NULL, NULL, simx_opmode_streaming);
// 		  }
  
// 		  // Loop principal
  
// 		  while(simxGetConnectionId(clientID) != -1) // Enquanto a simula��o estiver ativa
// 		  {
// 			  // Leitura dos sensores de vis�o
  
// 			  simxFloat* leftValues;
// 			  simxInt* leftValuesCount;
// 			  if(simxReadVisionSensor(clientID, leftSensorHandle, NULL, &leftValues, &leftValuesCount, simx_opmode_buffer) == simx_return_ok)
// 			  {
// 				  cout << "Intensidade sensor esquerdo: " << (float) leftValues[10] << std::endl;
// 			  }
  
// 			  simxFloat* middleValues;
// 			  simxInt* middleValuesCount;
// 			  if(simxReadVisionSensor(clientID, middleSensorHandle, NULL, &middleValues, &middleValuesCount, simx_opmode_buffer) == simx_return_ok)
// 			  {
// 				  cout << "Intensidade sensor central: " << (float) middleValues[10] << std::endl;
// 			  }
  
// 			  simxFloat* rightValues;
// 			  simxInt* rightValuesCount;
// 			  if(simxReadVisionSensor(clientID, rightSensorHandle, NULL, &rightValues, &rightValuesCount, simx_opmode_buffer) == simx_return_ok)
// 			  {
// 				  cout << "Intensidade sensor direito: " << (float) rightValues[10] << std::endl;
// 			  }
  
// 			  // Indica��o de qual sensor est� detectando a linha
  
// 			  bool sensorRead[3] = {false, false, false};
  
// 			  if(leftValues[10] < blackTS) sensorRead[0] = true;
// 			  else sensorRead[0] = false;
  
// 			  if(middleValues[10] < blackTS) sensorRead[1] = true;
// 			  else sensorRead[1] = false;
  
// 			  if(rightValues[10] < blackTS) sensorRead[2] = true;
// 			  else sensorRead[2] = false;
  
// 			  // Tomada de decis�o
  
// 			  float speed[2] = {0, 0};
  
// 			  if(sensorRead[0])
// 			  {
// 				  if(sensorRead[2])
// 				  {
// 					  speed[0] = minSpeed;
// 					  speed[1] = minSpeed;
// 				  }
// 				  else
// 				  {
// 					  speed[0] = minSpeed;
// 					  speed[1] = maxSpeed;
// 				  }
// 			  }
// 			  else
// 			  {
// 				  if(sensorRead[2])
// 				  {
// 					  speed[0] = maxSpeed;
// 					  speed[1] = minSpeed;
// 				  }
// 				  else
// 				  {
// 					  speed[0] = maxSpeed;
// 					  speed[1] = maxSpeed;
// 				  }
// 			  }
  
// 			  // Atua��o
  
// 			  simxSetJointTargetVelocity(clientID, leftMotorHandle, (simxFloat) speed[0], simx_opmode_streaming);
// 			  simxSetJointTargetVelocity(clientID, rightMotorHandle, (simxFloat) speed[1], simx_opmode_streaming);
  
// 			  // Tempo de loop
  
// 			  extApi_sleepMs(5);
// 		  }
  
// 		  simxFinish(clientID); // Fechando conex�o com o servidor
// 		  cout << "Conexao fechada!" << std::endl;
// 	  }
// 	  else cout << "Problemas para conectar o servidor!" << std::endl;
  
// 	  return 0;
//   }
  
  
