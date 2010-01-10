#ifndef COMPUTERROOM_H
#define COMPUTERROOM_H

#include "environment.h"

namespace cprog_game
{
  class ComputerRoom : public Environment
  {
  public:
    ComputerRoom(const std::string & name, const std::string & desc) : Environment(name,desc) {}
  
    void interact(Character* c);
  };
}

#endif // COMPUTERROOM_H
