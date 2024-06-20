/**
Relâmpago-Marquinhos

Projeto de Culminância de Eletiva de Robótica, Semestre 1/2024.
Código escrito por Renan / 3º A
Montagem por Artur / 3º D

https://github.com/lyricalsoul/relampago
https://github.com/lyricalsoul/relampago-app
*/

#include <Arduino.h>
#include <bt-ctrl.h>
#include <motor-ctrl.h>

#define BLUETOOTH_TX 2
#define BLUETOOTH_RX 3
#define H_IN_1 4
#define H_IN_2 5
#define H_IN_3 6
#define H_IN_4 7

MotorControl motorControl(H_IN_1, H_IN_2, H_IN_3, H_IN_4);
BluetoothControl bluetoothControl(BLUETOOTH_TX, BLUETOOTH_RX);

void setup() {
    Serial.begin(9600);
    motorControl.setup();
    bluetoothControl.setup();
}

void loop() {
    const auto opcode = bluetoothControl.runLoop();
    bool shouldLockControls = false;

    switch (opcode) {
        case OP_FORWARD:
            motorControl.forward();
            break;
        case OP_BACKWARD:
            motorControl.backward();
            break;
        case OP_LEFT:
            motorControl.left();
            break;
        case OP_RIGHT:
            motorControl.right();
            break;
        case OP_STOP:
            motorControl.stop();
            break;
        case OP_LOCK_STATE:
            shouldLockControls = !shouldLockControls;
            break;
        default:
            break;
    }

    delay(100);
    if (!shouldLockControls) {
        motorControl.stop();
    }
}