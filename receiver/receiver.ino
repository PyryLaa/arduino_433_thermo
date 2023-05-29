#include <U8g2lib.h>
#include <U8x8lib.h>
#include <RH_ASK.h>
#include <SPI.h>
#include <Wire.h>




RH_ASK driver;
U8X8_SH1106_128X64_NONAME_HW_I2C oled(U8X8_PIN_NONE, 19, 18);




void setup() {
  Serial.begin(9600);
  oled.begin();
  oled.setFont(u8x8_font_amstrad_cpc_extended_f);
  oled.setCursor(3,1);
  oled.print("Temperature");
  oled.drawUTF8(9, 3, "°C");
  if(!driver.init()){
    oled.clearDisplay();
    oled.setCursor(7,3);
    oled.print("Init failed");
  }
  

}

void loop() {
  
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);
  if (driver.recv(buf, &buflen)) {
    int i;
    oled.setCursor(7, 3);
    Serial.print((char*)buf);
  }

}
