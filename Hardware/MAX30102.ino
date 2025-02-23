#include <Wire.h>
#include "MAX30105.h"  // Use SparkFun MAX3010x library

MAX30105 particleSensor;

void setup() {
    Serial.begin(115200);
    Wire.begin();

    if (!particleSensor.begin(Wire, I2C_SPEED_STANDARD)) {
        Serial.println("MAX30102 not found. Check connections!");
        while (1);
    }
  
    particleSensor.setup();  // Default settings
    particleSensor.setPulseAmplitudeRed(0x0A);
    particleSensor.setPulseAmplitudeIR(0x0A);
}

void loop() {
    long irValue = particleSensor.getIR();
    long redValue = particleSensor.getRed();

    if (irValue < 50000) {
        Serial.println("Finger not detected");
    } else {
        Serial.print("IR: ");
        Serial.print(irValue);
        Serial.print(" Red: ");
        Serial.println(redValue);
    }
  
    delay(100);
}