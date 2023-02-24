#ifndef __mainframe__
#define __mainframe__

#include "frame.hpp"

//maximale länge für String
#define MAXLENZEIT 9

//Member variable
class MainFrame 
 : public Frame
{

public:
   MainFrame();

virtual 
  ~MainFrame();

virtual const char *
    getZeit() const { return clZeit; }

virtual const float &
   getTemperatur() const { return clTemperatur; }

virtual const unsigned int & 
   getLuftdruck() const { return clLuftdruck; }

virtual const unsigned int &
   getFeuchtigkeit() const { return clFeuchtigkeit; }

virtual void
   setZeit(const char[]);

virtual void 
//Temperatur, luftdruck und feuchtigkeit sind konstant.
   setTemperatur(const float &temperatur){ clTemperatur = temperatur; }

virtual void 
   setLuftdruck(unsigned int luftdruck){ clLuftdruck = luftdruck; }

virtual void 
   setFeuchtigkeit(unsigned int feuchtigkeit){ clFeuchtigkeit = feuchtigkeit; }
  

protected:
virtual void
   paint();

float 
   clTemperatur;
unsigned int 
   clFeuchtigkeit;
unsigned int 
   clLuftdruck;
char
   clZeit[MAXLENZEIT];
    

};

#endif
