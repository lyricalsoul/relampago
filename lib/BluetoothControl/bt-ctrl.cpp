//
// Created by renan martins on 20/06/2024.
//

#include "bt-ctrl.h"

BluetoothControl::BluetoothControl(const int tx, const int rx) {
    this->tx = tx;
    this->rx = rx;
    this->isInterfaceInitialized = false;
    this->interface = new SoftwareSerial(tx, rx);
}

void BluetoothControl::setup () const {
    // set up bt mate at default (115200 baud)
    interface->begin(BT_BAUD);

    // check if the module is responding
    if (!runATCommandAndCheck("AT")) {
        return;
    }

    // set name of the module
    runATCommand("AT+NAME=Relâmpago");
}

void BluetoothControl::runATCommand(const char* command) const {
    interface->println(command);
}

bool BluetoothControl::runATCommandAndCheck(const char *command) const {
    runATCommand(command);
    char response[24];
    interface->readBytes(response, 24);
    if (strcmp(response, "OK") != 0) {
        Serial.println("WARNING: The Bluetooth module has not responded with OK.");
        Serial.println("Please check the connections and try again.");
        return false;
    }

    return true;
}

bool BluetoothControl::checkInterface() {
    if (interface->available()) {
        if (!isInterfaceInitialized) {
            interface->println("U,9600,N");
            interface->begin(9600);
            isInterfaceInitialized = true;
        }
        return true;
    }

    Serial.println("Bluetooth control not available.");
    return false;
}

BluetoothOpcodes BluetoothControl::runLoop() {
    if (!this->checkInterface()) {
        return OP_NONE;
    }

    const char opcode = interface->read();
    switch (opcode) {
        case 'F':
            return OP_FORWARD;
        case 'B':
            return OP_BACKWARD;
        case 'L':
            return OP_LEFT;
        case 'R':
            return OP_RIGHT;
        case 'S':
            return OP_STOP;
        case 'K':
            return OP_LOCK_STATE;
        default:
            return OP_NONE;
    }
}
