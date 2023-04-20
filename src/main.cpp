#include <Arduino.h>
#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
char msg[8] = "hdfixi";
//RF24(uint16_t _cepin, uint16_t _cspin, uint16_t sck, uint16_t miso, uint16_t mosi)
RF24 radio(12, 14, 26, 25, 27);
const uint64_t p= 0x00011111;
int16_t values_to_send[5];
void setup(void) {
  Serial.begin(115200);
  radio.begin();
  radio.setChannel(30);
  radio.setPayloadSize(32);
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(p);
  pinMode(33,INPUT);
  pinMode(32,INPUT);
  pinMode(35,INPUT);
  pinMode(34,INPUT);
}
void loop(void) {


int16_t throttle = analogRead(33);
values_to_send[0]= map(throttle, 0, 4095, 2000, 1000);

int yaw = analogRead(32);
values_to_send[1]= map(yaw, 0, 4095, 1000, 2000);


int roll= analogRead(35);
values_to_send[2]= map(roll, 0, 4095, 1000, 2000);
int pitch = analogRead(34);
values_to_send[3]= map(pitch, 0, 4095,1000, 2000);

  Serial.print("throtlle:");
  Serial.print(values_to_send[0]);
   Serial.print("   Yaw:");
    Serial.print(values_to_send[1]);
   Serial.print("   Roll:");
    Serial.print(values_to_send[2]);
   Serial.print("   Pitch:");
    Serial.print(values_to_send[3]);
   Serial.println("   ");
radio.write(values_to_send, sizeof(values_to_send));
  
}
/*
 blue:4
purpil:3
green:2
yellow:1
*/ 