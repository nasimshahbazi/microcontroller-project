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
}
                              
void TestFrame :: handle
 (
   const Event &event
 )
{
   changed = true;
}


