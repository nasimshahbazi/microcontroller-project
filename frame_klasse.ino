#include <Arduino.h>
#include "frame.hpp"
#include "testframe.hpp"
#include "mainframe.hpp"

Frame *frame;
float temp = 11.2; 

void setup(void) 
{
   frame = new TestFrame();
   frame->init();
   //kommen die Werte von Sensor.
   //frame->setTemperatur(15.2);
   //frame->setFeuchtigkeit(45);
   //frame->setLuftdruck(1000);
   
}

void loop(void) 
{
  // picture loop  
   frame->clear();

   //frame->setTemperatur(temp);

   frame->draw();

   temp += 0.2;
  
   delay(2000);
}
