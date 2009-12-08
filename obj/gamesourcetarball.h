#ifndef GAMESOURCETARBALL_H
#define GAMESOURCETARBALL_H

#include "object.h"

class GameSourceTarball : public Object
{
public:
  GameSourceTarball(int value, const std::string& desc) :
      Object(ITEM_NAME,4,value,desc) {}

  void interact(Character* c);

  const static std::string ITEM_NAME;
};

#endif // GAMESOURCETARBALL_H
