//============================================================================
// Name        : warehousedock.cpp
// Author      : Victor T. Noppeney
// Version     :
// Copyright   : All rights reserved
// Description : Warehouse dock controller (human interface)
//============================================================================

#include "libraries/battery.h"

#define SLEEP_TIME 100
#define PRINT_CYCLE 100

int main(int argc, char **argv) {
    Battery robotBattery;
    int cycle_counter = 0;
    cout << "Robot battery monitor version 1.0" << endl;
    while(robotBattery.isActive()) {
        robotBattery.updateBatteryLevelSignal();
        extApi_sleepMs(SLEEP_TIME);
        if(cycle_counter % PRINT_CYCLE == 0 && cycle_counter != 0) {
            cout << "Battery level: " << robotBattery.getBatteryLevel() << "%" << endl;
            cycle_counter = 0;
        }
        cycle_counter++;
    }
    return 0;
}
