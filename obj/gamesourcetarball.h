#ifndef GAMESOURCETARBALL_H
#define GAMESOURCETARBALL_H

#include "object.h"

namespace cprog_game
{
  class GameSourceTarball : public Object
  {
  public:
    GameSourceTarball(const std::string& name, const std::string& desc, int value) :
        Object(name,4,value,desc) {}
  
    void interact(Character* c);
  };
}

#endif // GAMESOURCETARBALL_H
