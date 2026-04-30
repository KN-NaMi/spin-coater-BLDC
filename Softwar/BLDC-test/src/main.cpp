#include <Arduino.h>

const uint16_t DELAY = 100; 

#define AL 2
#define AH 3
#define BL 4
#define BH 5
#define CL 6
#define CH 7

void allOff() {
    //PORTD = 0x01010100; 
    digitalWrite(AL, HIGH);
    digitalWrite(AH, LOW);
    digitalWrite(BL, HIGH);
    digitalWrite(BH, LOW);
    digitalWrite(CL, HIGH);
    digitalWrite(CH, LOW);
    //delayMicroseconds(DELAY);
}

void step1() {
    allOff();
    digitalWrite(AH, HIGH);
    digitalWrite(BL, LOW);
}

void step2() {
    allOff();
    digitalWrite(AH, HIGH);
    digitalWrite(CL, LOW);
}

void step3() {
    allOff();
    digitalWrite(BH, HIGH);
    digitalWrite(CL, LOW);
}

void step4() {
    allOff();
    digitalWrite(BH, HIGH);
    digitalWrite(AL, LOW);
}

void step5() {
    allOff();
    digitalWrite(CH, HIGH);
    digitalWrite(AL, LOW);
}

void step6() {
    allOff();
    digitalWrite(CH, HIGH);
    digitalWrite(BL, LOW);
}

void setup() {
    for (int i = 2; i <= 7; i++) {
        pinMode(i, OUTPUT);
        digitalWrite(i, LOW);
    }
    pinMode(A0, INPUT);
    allOff();
}

void loop() {
    allOff();
    int sensorValue = analogRead(A0);
    int stepDelay = map(sensorValue, 0, 1023, 250, 1);
    
    step1(); delayMicroseconds(stepDelay);
    step2(); delayMicroseconds(stepDelay);
    step3(); delayMicroseconds(stepDelay);
    step4(); delayMicroseconds(stepDelay);
    step5(); delayMicroseconds(stepDelay);
    step6(); delayMicroseconds(stepDelay);
}