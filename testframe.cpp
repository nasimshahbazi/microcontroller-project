#include "testframe.hpp"

TestFrame :: TestFrame()
 : Frame()
{
}

TestFrame :: ~TestFrame()
{
  
}

void TestFrame :: paint()
{
   clU8g2->drawStr(0, 0, "QWERTZUIOPÜ");
   clU8g2->drawStr(0, 20, "ASDFGHJKLÖÄ");
   clU8g2->drawStr(0, 30, "iYXCVBNM");
   clU8g2->drawStr(0, 40, "1234567890");
   //clU8g2->drawStr(0, 50, "-/;:()$&@.,?!'");
   //clU8g2->drawStr(0, 60, "[]{}#%^*+=");
   // clU8g2->drawStr(0, 70, "_\~<>  .");
}
                              