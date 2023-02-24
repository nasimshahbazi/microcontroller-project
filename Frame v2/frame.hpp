#ifndef __frame__
#define __frame__

#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

class Event;

class Frame
{
public:
   Frame();
virtual 
  ~Frame();

virtual void 
   init();

virtual void
   clear();

virtual void
   draw();

virtual void
   handle(const Event &){}

protected:

U8G2_SSD1306_128X64_NONAME_F_HW_I2C *
   clU8g2;

virtual void
   paint();

bool
   changed;
   
};

#endif
