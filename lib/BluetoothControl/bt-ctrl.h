//
// Created by renan martins on 20/06/2024.
//

#ifndef BT_CTRL_H
#define BT_CTRL_H

#define BT_BAUD 115200
#include <Arduino.h>
#include <SoftwareSerial.h>

// class: BluetoothControl
// methods: setup() runLoop()
// enum: BluetoothOpcodes : int { OP_NONE, OP_FORWARD, OP_BACKWARD, OP_LEFT, OP_RIGHT, OP_STOP }

enum BluetoothOpcodes : int {
    OP_NONE,
    OP_FORWARD,
    OP_BACKWARD,
    OP_LEFT,
    OP_RIGHT,
    OP_STOP,
    OP_LOCK_STATE
};

class BluetoothControl {
    int tx;
    int rx;
    bool isInterfaceInitialized;
    SoftwareSerial* interface;

    bool checkInterface();
public:
    BluetoothControl(int tx, int rx);

    void setup() const;

    void runATCommand(const char *command) const;

    bool runATCommandAndCheck(const char *command) const;

    BluetoothOpcodes runLoop();
};

#endif //BT_CTRL_H
