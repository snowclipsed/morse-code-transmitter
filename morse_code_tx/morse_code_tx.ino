// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 
#include<string.h>

 
// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
 
void setup() {
  Serial.begin(9600); // Debugging only
  if (!rf_driver.init())
    Serial.println("init failed");
  else
    Serial.println("TX");
}

void loop() {
if (Serial.available() > 0)
  {
String strMsg = "";
int i;

strMsg = Serial.readString();
i = (strMsg.length() + 1);
char msg[i] = {};
Serial.print("Sent: ");
Serial.println(strMsg);
Serial.print("Size: ");
Serial.println(i);
strMsg.toCharArray(msg, i);
rf_driver.send((uint8_t *)msg, strlen(msg));
rf_driver.waitPacketSent();
delay(200);
 }
}
