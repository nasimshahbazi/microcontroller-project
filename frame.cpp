#include "frame.hpp"

//U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

Frame :: Frame()
 : changed(true)
{
   clU8g2 = new U8G2_SSD1306_128X64_NONAME_F_HW_I2C(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
   clU8g2->begin();  
}

Frame :: ~Frame()
{
   delete clU8g2;
}

void Frame :: init()
{
   changed = true;
   // clU8g2->setFont(u8g2_font_6x10_mf);
   clU8g2->setFont(u8g2_font_10x20_mf);
   //clU8g2->setFont(u8g2_font_10x20_t_arabic);
   
   clU8g2->setFontRefHeightExtendedText();
   clU8g2->setDrawColor(1);
   clU8g2->setFontPosTop();
   clU8g2->setFontDirection(0);
}

void Frame :: clear()
{
   changed = true;
   clU8g2->clearBuffer();
}

void Frame :: draw()
{
   if (!changed)
      return;
      
   clear();
   paint();
   clU8g2->sendBuffer();
   
   changed = false;
}

void Frame :: paint()
{
   clU8g2->drawStr(0, 0, "Hello, new World!");
}
