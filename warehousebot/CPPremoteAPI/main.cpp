/*
    Client of V-REP simulation server (remoteApi)
    Copyright (C) 2015  Rafael Alceste Berri rafaelberri@gmail.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// Habilite o server antes na simulação V-REP com o comando Lua:
// simExtRemoteApiStart(portNumber) -- inicia servidor remoteAPI do V-REP

extern "C" {
  #include "remoteApi/extApi.h"
}

#include <iostream>
#include <string>

#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

int main(int argc, char **argv) 
{
	string serverIP = "127.0.0.1";
	int serverPort = 19999;

	// Handles dos componentes da cena
	int leftMotorHandle = 0, rightMotorHandle = 0;
	int noseSensorHandle = 0;
	int leftSensorHandle = 0, middleSensorHandle = 0, rightSensorHandle = 0;

	// Variáveis dos motores
	float maxSpeed = 2, minSpeed = 0.2;

	// Variáveis do sensor de visão
	float blackTS = 0.21;
  
	// Variáveis de cena
	// float minMaxSpeed[2] = {50 * M_PI / 180, 300 * M_PI / 180};
	// int backUntilTime = -1;
  
	int clientID=simxStart((simxChar*) serverIP.c_str(), serverPort, true, true, 2000, 5);
  
	if (clientID != -1)
	{
		cout << "Servidor conectado!" << std::endl;
    
		// Inicialização dos motores

		if(simxGetObjectHandle(clientID, (const simxChar*) "leftMotor", (simxInt *) &leftMotorHandle, (simxInt) simx_opmode_oneshot_wait) != simx_return_ok)
			cout << "Handle do motor esquerdo nao encontrado!" << std::endl;
		else
			cout << "Conectado ao motor esquerdo!" << std::endl;
    
		if(simxGetObjectHandle(clientID, (const simxChar*) "rightMotor", (simxInt *) &rightMotorHandle, (simxInt) simx_opmode_oneshot_wait) != simx_return_ok)
			cout << "Handle do motor direito nao encontrado!" << std::endl;
		else
			cout << "Conectado ao motor direito!" << std::endl;
    
		// Inicialização dos sensores

		if(simxGetObjectHandle(clientID, (const simxChar*) "sensingNose", (simxInt *) &noseSensorHandle, (simxInt) simx_opmode_oneshot_wait) != simx_return_ok)
			cout << "Handle do sensor do nariz nao encontrado!" << std::endl;
		else
		{
			cout << "Conectado ao sensor do nariz!" << std::endl;
			simxReadProximitySensor(clientID, noseSensorHandle, NULL, NULL, NULL, NULL, simx_opmode_streaming);
		}

		if(simxGetObjectHandle(clientID, (const simxChar*) "leftSensor", (simxInt *) &leftSensorHandle, (simxInt) simx_opmode_oneshot_wait) != simx_return_ok)
			cout << "Handle do sensor esquerdo nao encontrado!" << std::endl;
		else
		{
			cout << "Conectado ao sensor esquerdo!" << std::endl;
			simxReadVisionSensor(clientID, leftSensorHandle, NULL, NULL, NULL, simx_opmode_streaming);
		}

		if(simxGetObjectHandle(clientID, (const simxChar*) "middleSensor", (simxInt *) &middleSensorHandle, (simxInt) simx_opmode_oneshot_wait) != simx_return_ok)
			cout << "Handle do sensor central nao encontrado!" << std::endl;
		else
		{
			cout << "Conectado ao sensor central!" << std::endl;
			simxReadVisionSensor(clientID, middleSensorHandle, NULL, NULL, NULL, simx_opmode_streaming);
		}

		if(simxGetObjectHandle(clientID, (const simxChar*) "rightSensor", (simxInt *) &rightSensorHandle, (simxInt) simx_opmode_oneshot_wait) != simx_return_ok)
			cout << "Handle do sensor direito nao encontrado!" << std::endl;
		else
		{
			cout << "Conectado ao sensor direito!" << std::endl;
			simxReadVisionSensor(clientID, rightSensorHandle, NULL, NULL, NULL, simx_opmode_streaming);
		}

		// Loop principal

		while(simxGetConnectionId(clientID) != -1) // Enquanto a simulação estiver ativa
		{
			// Leitura dos sensores de visão

			simxFloat* leftValues;
			simxInt* leftValuesCount;
			if(simxReadVisionSensor(clientID, leftSensorHandle, NULL, &leftValues, &leftValuesCount, simx_opmode_buffer) == simx_return_ok)
			{
				cout << "Intensidade sensor esquerdo: " << (float) leftValues[10] << std::endl;
			}

			simxFloat* middleValues;
			simxInt* middleValuesCount;
			if(simxReadVisionSensor(clientID, middleSensorHandle, NULL, &middleValues, &middleValuesCount, simx_opmode_buffer) == simx_return_ok)
			{
				cout << "Intensidade sensor central: " << (float) middleValues[10] << std::endl;
			}

			simxFloat* rightValues;
			simxInt* rightValuesCount;
			if(simxReadVisionSensor(clientID, rightSensorHandle, NULL, &rightValues, &rightValuesCount, simx_opmode_buffer) == simx_return_ok)
			{
				cout << "Intensidade sensor direito: " << (float) rightValues[10] << std::endl;
			}

			// Indicação de qual sensor está detectando a linha

			bool sensorRead[3] = {false, false, false};

			if(leftValues[10] < blackTS) sensorRead[0] = true;
			else sensorRead[0] = false;

			if(middleValues[10] < blackTS) sensorRead[1] = true;
			else sensorRead[1] = false;

			if(rightValues[10] < blackTS) sensorRead[2] = true;
			else sensorRead[2] = false;

			// Tomada de decisão

			float speed[2] = {0, 0};

			if(sensorRead[0])
			{
				if(sensorRead[2])
				{
					speed[0] = minSpeed;
					speed[1] = minSpeed;
				}
				else
				{
					speed[0] = minSpeed;
					speed[1] = maxSpeed;
				}
			}
			else
			{
				if(sensorRead[2])
				{
					speed[0] = maxSpeed;
					speed[1] = minSpeed;
				}
				else
				{
					speed[0] = maxSpeed;
					speed[1] = maxSpeed;
				}
			}

			// Atuação

			simxSetJointTargetVelocity(clientID, leftMotorHandle, (simxFloat) speed[0], simx_opmode_streaming);
			simxSetJointTargetVelocity(clientID, rightMotorHandle, (simxFloat) speed[1], simx_opmode_streaming);

			// Tempo de loop

			extApi_sleepMs(5);
		}

		simxFinish(clientID); // Fechando conexão com o servidor
		cout << "Conexao fechada!" << std::endl;
    }
	else cout << "Problemas para conectar o servidor!" << std::endl;

	return 0;
}

