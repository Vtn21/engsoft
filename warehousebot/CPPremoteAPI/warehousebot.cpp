//============================================================================
// Name        : warehousebot.cpp
// Author      : Victor T. Noppeney
// Version     :
// Copyright   : All rights reserved
// Description : Warehouse robot controller (autonomous)
//============================================================================

#include "libraries/statemachine.h"

int main(int argc, char **argv) {
    StateMachine pioneer;
    if(pioneer.run()) {
        return 0;    
    }
    else {
        cerr << "Robot operation ended with errors" << endl;
        return -1;
    }
}
  
