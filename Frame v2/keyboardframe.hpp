#ifndef __keyboardframe__
#define __keyboardframe__

#include "frame.hpp"

class KeyboardFrame
 : public Frame
{

public:
   KeyboardFrame();

virtual
  ~KeyboardFrame();

virtual const unsigned int &
   getSpalte() const{ return clSpalte; }

virtual const unsigned int &
   getZeile() const{ return clZeile; }

virtual const unsigned int &
   getGruppe() const{ return clGruppe; }

virtual void
   setSpalte(const unsigned int &spalte){ clSpalte = spalte; changed = true; }

virtual void 
   setZeile(const unsigned int &zeile){ clZeile = zeile; changed = true; }

virtual void 
   setGruppe(const unsigned int &gruppe){ clGruppe = gruppe; changed = true; }

virtual void
   handle(const Event &);
   
protected:

virtual void
   paint();

virtual void
   correctPos();
   
unsigned int 
   clSpalte;
unsigned int 
   clZeile;
unsigned int
   clGruppe;

const char 
   clZeichen [9][20] = {"QWERTZUIOP","ASDFGHJKL", "YXCVBNM", 
                        "qwertzuiop", "asdfghjkl", "yxcvbnm", 
                        "1234567890", "-/:;()&@'!?,.", "<>\"345645 "};
    //zweidimensionale array[]
char
   clPassword[25];
};

#endif
