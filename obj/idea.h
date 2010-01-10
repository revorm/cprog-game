#ifndef IDEA_H
#define IDEA_H

#include "object.h"

namespace cprog_game
{
  class Idea : public Object
  {
  public:
    Idea(const std::string& name, const std::string& desc, int value) :
        Object(name,1,value,desc){}
    void interact(Character*);
  };
}

#endif // IDEA_H
