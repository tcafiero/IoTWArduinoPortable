/*
  Software serial multple serial test

 Receives from the two software serial ports,
 sends to the hardware serial port.

 In order to listen on a software port, you call port.listen().
 When using two software serial ports, you have to switch ports
 by listen()ing on each one in turn. Pick a logical time to switch
 ports, like the end of an expected transmission, or when the
 buffer is empty. This example switches ports when there is nothing
 more to read from a port

 The circuit:
 Two devices which communicate serially are needed.
 * First serial device's TX attached to digital pin A0, RX to pin A1
 * Second serial device's TX attached to digital pin A2, RX to pin A3

 This example code is in the public domain.

 */

#include <SoftwareSerial.h>
// software serial #1: TX = digital pin A1, RX = digital pin A0
SoftwareSerial portOne(A0, A1);

// software serial #2: TX = digital pin A3, RX = digital pin A2
SoftwareSerial portTwo(7, 8);

void setup()
{
  // Open serial communications and wait for port to open:
  //Serial.begin(9600);

  // Start each software serial port
  portOne.begin(115200);
  portTwo.begin(115200);
}

void loop()
{
  // By default, the last intialized port is listening.
  // when you want to listen on a port, explicitly select it:
  portTwo.listen();

  portOne.println("Data from Serial:");
  // while there is data coming in, read it
  // and send to the hardware serial port:
  while (portTwo.available() > 0) {
    char inByte = portTwo.read();
    portOne.write(inByte);
  }
}

