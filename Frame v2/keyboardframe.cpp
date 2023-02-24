#include "keyboardframe.hpp"
#include "event.hpp"

#include <string.h>

#define PASSWORDLENGTH 8
#define MAXROWS        3

KeyboardFrame :: KeyboardFrame()
 : Frame(),
   clSpalte(0),
   clZeile(0),
   clGruppe(0)
{
   strcpy(clPassword, "long Passwort");
   //initialisieren die clPassword.

//   Serial.begin(9600);
}

KeyboardFrame :: ~KeyboardFrame()
{
}

void KeyboardFrame :: paint()
{
   const unsigned int xstartpos = 10;
   const unsigned int ystartpos = 0;
   const unsigned int xoffset = 10;
   const unsigned int yoffset = 13;
  
   char drawstr[2];
   drawstr[1] = 0;
        
   for (unsigned int j = 0; j < MAXROWS; ++j)
   {
      for (unsigned int i = 0; i < strlen(clZeichen[j]); ++i)
      //strlen: findet die länge von memberVariable clZeichen
      {
         drawstr[0] = clZeichen[j + clGruppe * MAXROWS][i];
         if ((j == clZeile) && (i == clSpalte))
         {
            clU8g2->setDrawColor(0);
            clU8g2->drawStr(xstartpos + xoffset * i, 
                            ystartpos + yoffset * j,
                            drawstr);                            
                            //&clZeichen[j + clGruppe * MAXROWS][i]);
            clU8g2->setDrawColor(1);
         }
         else
         {
            clU8g2->drawStr(xstartpos + xoffset * i, 
                            ystartpos + yoffset * j,
                            drawstr);
                            //&clZeichen[j + clGruppe * MAXROWS][i]);
         }
      }
   }

   clU8g2->drawLine(0, 45, 127, 45);
   clU8g2->drawLine(0, 63, 127, 63);
   clU8g2->setFont(u8g2_font_twelvedings_t_all);
   //das ist die Font für die Symbole ist.

   clU8g2->drawStr(10, 50, "l");
   //Scloss Symbol ist nummer108, und diese Nummer muss man in ASCII Tabelle als alphabet finden.
   //https://github.com/olikraus/u8g2/wiki/fnticons

   /*clU8g2->setFont(u8g2_font_emoticons21_tr);
   clU8g2->drawStr(10, 50, "0");
   clU8g2->drawStr(25,50,"&"); 
    */
    //wir mussen die Font nochmal wechseln.
   clU8g2->setFont(u8g2_font_8x13_mf);
   //clU8g2->drawStr(40, 50, clPassword);

   unsigned int length = 0;
   if ((length = strlen(clPassword)) > PASSWORDLENGTH)
   { 
      char *dummy = clPassword + length - PASSWORDLENGTH;

      clU8g2->setFont(u8g2_font_open_iconic_all_2x_t);
      clU8g2->drawStr(20, 50,"M");

      clU8g2->setFont(u8g2_font_8x13_mf);
      clU8g2->drawStr(40, 50, dummy);
   }
   else
   {
      clU8g2->drawStr(30, 50, clPassword);
   }
}

void KeyboardFrame :: correctPos()
{
   if (clSpalte >= strlen(clZeichen[clZeile]))
      clSpalte = strlen(clZeichen[clZeile]) - 1;
}
         
void KeyboardFrame :: handle
 (
    const Event &event
 )
{
   if (event.getName() == Event::LEFT)
   {
      changed = true;     
      if (clSpalte <= 0)
         clSpalte = strlen(clZeichen[clZeile]) - 1;
      else
         --clSpalte;
   }
   else if (event.getName() == Event::RIGHT)
   { 
      changed = true;
      if (clSpalte >= strlen(clZeichen[clZeile]) - 1)
         clSpalte = 0;
      else
         ++clSpalte;
   }   
   else if (event.getName() == Event::UP)
   { 
      changed = true;
      if (clZeile <= 0)
         clZeile = MAXROWS - 1;
      else
         --clZeile;

      correctPos();     
   } 
   else if (event.getName() == Event::DOWN)
   { 
      changed = true;
      if (clZeile >= MAXROWS - 1)
         clZeile = 0;
      else
         ++clZeile;

      correctPos();     
   } 
   else if (event.getName() == Event::SELECT)
   {
      Serial.println("Es wurde select ausgewaehlt. ");
      Serial.print("Gruppe: ");
      Serial.println(clGruppe);      
      Serial.print("Zeile: ");
      Serial.println(clZeile);
      Serial.print("Spalte: ");
      Serial.println(clSpalte);
   }   
} 

   

