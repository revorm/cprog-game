#ifndef GAMESOURCETARBALL_H
#define GAMESOURCETARBALL_H

#include "object.h"

class GameSourceTarball : public Object
{
public:
  GameSourceTarball(const std::string& name, int value, const std::string& desc) :
      Object(name,4,value,desc) {}

  void interact(Character* c);

};

#endif // GAMESOURCETARBALL_H
