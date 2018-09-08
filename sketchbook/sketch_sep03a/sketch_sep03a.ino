#include <ArduinoJson.h>


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
const size_t bufferSize = 2*JSON_ARRAY_SIZE(2) + JSON_OBJECT_SIZE(4);
DynamicJsonBuffer jsonBuffer(bufferSize);

JsonObject& root = jsonBuffer.createObject();
root["sensor"] = "gps";
root["time"] = 1351824120;

JsonArray& accel = root.createNestedArray("accel");
accel.add(48.75608);
accel.add(2.302038);

JsonArray& mag = root.createNestedArray("mag");
mag.add(48.75608);
mag.add(2.302038);

root.printTo(Serial);  

}

void loop() {
  // put your main code here, to run repeatedly:

}
