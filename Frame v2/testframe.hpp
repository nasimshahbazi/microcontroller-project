#ifndef __testframe__
#define __testframe__

#include "frame.hpp"

class TestFrame
  : public Frame 
{
public:
   TestFrame();
virtual 
  ~TestFrame();

virtual void
   handle(const Event &);

protected:
virtual void
   paint();

};

#endif
