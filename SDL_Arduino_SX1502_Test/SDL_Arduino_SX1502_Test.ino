


#include <Wire.h>

#include "SDL_Arduino_SX1502.h"


SDL_Arduino_SX1502 sx1502;


void setup() {
  
  
    Wire.begin();

    Serial.begin(9600);
    // put your setup code here, to run once:
  
  
    byte error, address;
    int nDevices;
  
    Serial.println("");
    Serial.println("--------------------------");
    Serial.println("SDL_Arduino_SX1502_Test");
    Serial.println("Version 1.1");
/*
    nDevices = 0;
    for(address = 1; address < 127; address++ ) 
    {
      // The i2c_scanner uses the return value of
      // the Write.endTransmisstion to see if
      // a device did acknowledge to the address.
      Wire.beginTransmission(address);
      error = Wire.endTransmission();
  
      if (error == 0)
      {
        Serial.print("I2C device found at address 0x");
        if (address<16) 
          Serial.print("0");
        Serial.print(address,HEX);
        Serial.println("");
  
        nDevices++;
      }
      else if (error==4) 
      {
        Serial.print("Unknow error at address 0x");
        if (address<16) 
          Serial.print("0");
        Serial.println(address,HEX);
      }    
    }
    if (nDevices == 0)
      Serial.println("No I2C devices found\n");
    else
      Serial.println("done\n");
*/
}

void loop() {
 
  // blink IO 0 to see LED
  
  sx1502.setDirectionGPIOChannel(SX1502_REG_IO0, SX1502_OUTPUT);  
  sx1502.setDirectionGPIOChannel(SX1502_REG_IO1, SX1502_OUTPUT);
  sx1502.setDirectionGPIOChannel(SX1502_REG_IO2, SX1502_OUTPUT);
  sx1502.setDirectionGPIOChannel(SX1502_REG_IO3, SX1502_OUTPUT);
  //sx1502.setPullupGPIOChannel(SX1502_REG_IO0, SX1502_ON);
  //sx1502.setPulldownGPIOChannel(SX1502_REG_IO0, SX1502_ON);
  byte value;
    
  while (1)
  {
    Serial.println("----------------");
    sx1502.writeGPIO(0x01);
    delay(1000);
    Serial.println("++++++++++++++");
    value = sx1502.readGPIO();
    Serial.print("GPIO Value =");
    Serial.println(value, HEX);
    
    sx1502.writeGPIO(0x00);
    delay(1000);
    Serial.println("----------------");
      Serial.println("----------------");
    sx1502.writeGPIO(0x02);
    delay(1000);
    Serial.println("++++++++++++++");
    value = sx1502.readGPIO();
    Serial.print("GPIO Value =");
    Serial.println(value, HEX);
    
    sx1502.writeGPIO(0x00);
    delay(1000);
    Serial.println("----------------");
    
    Serial.println("----------------");
    sx1502.writeGPIO(0x04);
    delay(1000);
    Serial.println("++++++++++++++");
    value = sx1502.readGPIO();
    Serial.print("GPIO Value =");
    Serial.println(value, HEX);
    
    sx1502.writeGPIO(0x00);
    delay(1000);
    Serial.println("----------------");
   
    Serial.println("----------------");
    sx1502.writeGPIO(0x08);
    delay(1000);
    Serial.println("++++++++++++++");
    value = sx1502.readGPIO();
    Serial.print("GPIO Value =");
    Serial.println(value, HEX);
    
    sx1502.writeGPIO(0x00);
    delay(1000);
    Serial.println("----------------");
    
  }
  

}
