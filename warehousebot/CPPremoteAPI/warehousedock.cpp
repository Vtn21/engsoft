//============================================================================
// Name        : warehousedock.cpp
// Author      : Victor T. Noppeney
// Version     :
// Copyright   : All rights reserved
// Description : Warehouse dock controller (human interface)
//============================================================================

#include "libraries/dock.h"

int main(int argc, char** argv) {
    Dock dockController;
    int option, dock;
    while(dockController.isActive()) {
        cout << endl << "Dock controller version 1.0" << endl <<
                        "Choose option and press ENTER:" << endl <<
                        "1 - Spawn box" << endl <<
                        "2 - Remove box" << endl;
        cin >> option;
        switch(option) {
            case 1:
                cout << "Choose desired dock (0 or 1): ";
                cin >> dock;
                if(dockController.spawnBox(dock)) cout << "Box successfully spawned at dock #" << dock << endl;
                else cerr << "Unable to spawn box at dock #" << dock << endl;
                break;
            case 2:
                cout << "Choose desired dock (0 or 1): ";
                cin >> dock;
                if(dockController.removeBox(dock)) cout << "Box successfully removed, dock #" << dock << " is now empty" << endl;
                else cerr << "Unable to remove box from dock #" << dock << endl;
                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
    }
}