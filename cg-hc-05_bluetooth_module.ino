/*
 * Interfacing:
 * http://mechstuff.com/control-leds-with-your-android-arduino-bluetooth-module-tutorial/
 * http://solderer.tv/data-transfer-between-android-and-arduino-via-bluetooth/
 *      
 *    PINOUT: 
 *        _____________________________
 *       |  ARDUINO UNO   >>>   HC-50  |
 *        -----------------------------
 *        GND      >>>   GND
 *        5v       >>>   VCC(+5v)    
 *        RX(<-0)  >>>   TX
 *        TX(<-1)  >>>   RX
 *        D8       >>>   Anode of LED, long tail(OUTPUT)
 *        GND      >>>   Cathod of LED, short tail.
 *
 *    NOTE: TX and RX pin will be wired after uploading the source.
 *
 *        Created on: Dec 30, 2018
 *        Author: Md. Rashadul Alam
 *        Email: rashed.droid@gmail.com
 */

#include <SoftwareSerial.h>

void setup() {
Serial.begin(9600);
 pinMode(8, OUTPUT); // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0)
   {     
      char data= Serial.read(); // reading the data received from the bluetooth module
      switch(data)
      {
        case 'a': digitalWrite(8, HIGH);break; // when a is pressed on the app on your smart phone
        case 'd': digitalWrite(8, LOW);break; // when d is pressed on the app on your smart phone
        default : break;
      }
      Serial.println(data);
   }
   delay(50);
}
