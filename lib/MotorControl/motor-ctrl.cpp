//
// Created by renan martins on 20/06/2024.
//

#include "motor-ctrl.h"

MotorControl::MotorControl(int h_in_1, int h_in_2, int h_in_3, int h_in_4) {
    this->h_in_1 = h_in_1;
    this->h_in_2 = h_in_2;
    this->h_in_3 = h_in_3;
    this->h_in_4 = h_in_4;

    pinMode(h_in_1, OUTPUT);
    pinMode(h_in_2, OUTPUT);
    pinMode(h_in_3, OUTPUT);
    pinMode(h_in_4, OUTPUT);
}

void MotorControl::setup() const {
    digitalWrite(h_in_1, LOW);
    digitalWrite(h_in_2, LOW);
    digitalWrite(h_in_3, LOW);
    digitalWrite(h_in_4, LOW);
}

void MotorControl::forward() const {
    digitalWrite(h_in_1, HIGH);
    digitalWrite(h_in_2, LOW);
    digitalWrite(h_in_3, HIGH);
    digitalWrite(h_in_4, LOW);
}

void MotorControl::backward() const {
    digitalWrite(h_in_1, LOW);
    digitalWrite(h_in_2, HIGH);
    digitalWrite(h_in_3, LOW);
    digitalWrite(h_in_4, HIGH);
}

void MotorControl::left() const {
    digitalWrite(h_in_1, LOW);
    digitalWrite(h_in_2, HIGH);
    digitalWrite(h_in_3, HIGH);
    digitalWrite(h_in_4, LOW);
}

void MotorControl::right() const {
    digitalWrite(h_in_1, HIGH);
    digitalWrite(h_in_2, LOW);
    digitalWrite(h_in_3, LOW);
    digitalWrite(h_in_4, HIGH);
}

void MotorControl::stop() const {
    digitalWrite(h_in_1, LOW);
    digitalWrite(h_in_2, LOW);
    digitalWrite(h_in_3, LOW);
    digitalWrite(h_in_4, LOW);
}
