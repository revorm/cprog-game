#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player : public Character
{
public:
  Player(const std::string& name) : Character(name) {}
};

#endif // PLAYER_H
