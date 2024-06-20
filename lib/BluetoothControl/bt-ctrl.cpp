//
// Created by renan martins on 20/06/2024.
//

#include "bt-ctrl.h"

BluetoothControl::BluetoothControl(const int tx, const int rx) {
    this->tx = tx;
    this->rx = rx;
    this->interface = new SoftwareSerial(tx, rx);
}

void BluetoothControl::setup () const {
    // set up bt mate at default (115200 baud)
    interface->begin(BT_BAUD);
    Serial.println("Bluetooth control initialized.");
    interface->print("$$$");
}

BluetoothOpcodes BluetoothControl::runLoop() const {
    if (interface->available() > 0) {
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
    return OP_NONE;
}
