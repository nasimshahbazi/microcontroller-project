#ifndef __event__
#define __event__

class Event
{
public:

enum name {NOOP = 0, UP, DOWN, LEFT, RIGHT, SELECT};

   Event(const name &n = NOOP);

virtual
  ~Event();

virtual const name &
   getName() const{ return clIdEvent; }

protected:

name
   clIdEvent;

};

#endif
