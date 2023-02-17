#include "mainframe.hpp";

MainFrame :: MainFrame()
 : clTemperatur(0),
   clFeuchtigkeit(0),
   clLuftdruck(0)
{
  //get Methode für Zeit, muss für ganze Feld extera initialisiert werden.
   for (unsigned int i = 0; i < MAXLENZEIT; ++i)
   {
      clZeit[i] = 0;
   }
}

MainFrame :: ~MainFrame()
{
}

//set Methode, es ist ein Feld und das gesamte Feld muss kopiert werden.
void MainFrame :: setZeit
 (
   const char zeit[]
 )
{
  for(int i = 0; i < MAXLENZEIT; ++i)
  {
    clZeit[i] = zeit[i];
  } 
}

void MainFrame :: paint()
{
   //clU8g2->setFont(u8g2_font_unifont_t_arabic);

   clU8g2->drawLine(0, 30, 127,30);
   clU8g2->drawLine(0, 45, 127,45);
   clU8g2->drawLine(127/2, 30, 127/2,64);
   
   clU8g2->drawFrame(0,0,127,63);
   clU8g2->setFont(u8g2_font_10x20_mf);
  //Interger zu String umwandeln.
   char dummy[10];
   sprintf(dummy, "%3.1f °C", clTemperatur);
   
   clU8g2->drawUTF8(10,10, dummy);

   clU8g2->setFont(u8g2_font_6x10_mf);
   //2d zwei stellen interger zahl.
   sprintf(dummy, "%2d %%", clFeuchtigkeit);
   clU8g2->drawUTF8(69, 50, dummy);

   clU8g2->setFont(u8g2_font_6x10_mf);
   clU8g2->drawUTF8(69, 35, "Hallo");

   clU8g2->setFont(u8g2_font_6x10_mf);
   sprintf(dummy, "%4d hPa", clLuftdruck);
   clU8g2->drawUTF8(5,50, dummy);
   
   clU8g2->setFont(u8g2_font_6x10_mf);
   clU8g2->drawUTF8(5, 35, clZeit);
 
   //clU8g2->setFont(u8g2_font_unifont_t_emoticons);
   //clU8g2->setFont(u8g2_font_emoticons21_tr);
   // clU8g2->drawUTF8(10, 10, "0");
}