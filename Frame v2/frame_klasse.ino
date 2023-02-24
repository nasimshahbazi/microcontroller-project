#include <Arduino.h>
#include "frame.hpp"
#include "testframe.hpp"
#include "mainframe.hpp"
#include "keyboardframe.hpp"
#include "event.hpp"

#define PIN_UP     14
#define PIN_DOWN   13
#define PIN_LEFT   15
#define PIN_RIGHT  12
#define PIN_SELECT 00

#define DEBOUNCE 20

KeyboardFrame *frame;
Event event;

unsigned long presstime;
unsigned int thepin;

void IRAM_ATTR onclick
 (
   const Event &theevent 
 )
{
   Serial.print("clicked ");
   event = theevent;   
   
   if (event.getName() == Event::UP)
   {    
      Serial.println("UP");
      thepin = PIN_UP;
   }      
   if (event.getName() == Event::DOWN)
   {
      Serial.println("DOWN");
      thepin = PIN_DOWN;      
   }
   if (event.getName() == Event::LEFT)
   {    
      Serial.println("LEFT");
      thepin = PIN_LEFT;
   }      
   if (event.getName() == Event::RIGHT)
   {
      Serial.println("RIGHT");
      thepin = PIN_RIGHT;
   }      
   if (event.getName() == Event::SELECT)
   {
      Serial.println("SELECT");
      thepin = PIN_SELECT;
   }      
}

void IRAM_ATTR onclickup(){ onclick(Event(Event::UP)); }
void IRAM_ATTR onclickdown(){ onclick(Event(Event::DOWN)); }
void IRAM_ATTR onclickleft(){ onclick(Event(Event::LEFT)); }
void IRAM_ATTR onclickright(){ onclick(Event(Event::RIGHT)); }
void IRAM_ATTR onclickselect(){ onclick(Event(Event::SELECT)); }

void setup(void) 
{
   Serial.begin(9600);

   presstime = millis();

   pinMode(PIN_UP, INPUT);
   pinMode(PIN_DOWN, INPUT);
   pinMode(PIN_LEFT, INPUT);
   pinMode(PIN_RIGHT, INPUT);
   pinMode(PIN_SELECT, INPUT_PULLUP);
   
   frame = new KeyboardFrame();
   frame->init();

   attachInterrupt(digitalPinToInterrupt(PIN_UP), onclickup, RISING);
   attachInterrupt(digitalPinToInterrupt(PIN_DOWN), onclickdown, RISING);
   attachInterrupt(digitalPinToInterrupt(PIN_LEFT), onclickleft, RISING);
   attachInterrupt(digitalPinToInterrupt(PIN_RIGHT), onclickright, RISING);
   attachInterrupt(digitalPinToInterrupt(PIN_SELECT), onclickselect, FALLING);
   
   
}

#define SHOWSPEED 100

void loop(void) 
{
   frame->handle(Event(Event::RIGHT));
   frame->handle(Event(Event::DOWN));
   
   frame->handle(event);
   event = Event(Event::NOOP);
   frame->draw();
   
   delay(SHOWSPEED);
}
