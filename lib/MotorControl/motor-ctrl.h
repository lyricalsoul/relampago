//
// Created by renan martins on 20/06/2024.
//

#ifndef MOTOR_CTRL_H
#define MOTOR_CTRL_H

#include <Arduino.h>
class MotorControl {
    int h_in_1;
    int h_in_2;
    int h_in_3;
    int h_in_4;
public:
    MotorControl(int h_in_1, int h_in_2, int h_in_3, int h_in_4);
    void setup() const;
    void forward() const;
    void backward() const;
    void left() const;
    void right() const;
    void stop() const;
};

#endif //MOTOR_CTRL_H
