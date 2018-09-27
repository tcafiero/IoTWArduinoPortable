#include <SoftwareSerial.h>
#include <pca10040.h>

#define PIN_TX     ARDUINO_7_PIN
#define PIN_RX     ARDUINO_8_PIN
SoftwareSerial     mySerial(PIN_RX,PIN_TX);



void setup() {
  // put your setup code here, to run once:
    mySerial.begin(9600);
    Serial.begin(9600);
    mySerial.println("Hello World!!!!!");
    Serial.println("Hello World");
}

void loop() {
  // put your main code here, to run repeatedly:

}
