#include <RH_ASK.h>
#include <SPI.h>
#include <TimerOne.h>


RH_ASK driver;

const int SENSOR_PIN = A0;
float read = 0, volt = 0;
int temp = 0;

void setup() {
  //Timer1.initialize(2000000);
  //Timer1.attachInterrupt(get_temp);
  driver.init();
  
}

void loop() {
  char *msg = "Hello world!";
  driver.send((uint8_t*) msg, strlen(msg));
  driver.waitPacketSent();
  delay(1000);
}

/*void get_temp(){
  read = analogRead(SENSOR_PIN);
  volt = (read/1024.0) * 5.0;
  temp = floor((volt - 0.5) * 100);
}*/