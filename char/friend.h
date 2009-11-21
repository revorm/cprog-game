#ifndef FRIEND_H
#define FRIEND_H

#include "character.h"

class Friend : public Character
{
public:
  Friend(const std::string& name) : Character(name) {}
};

#endif // FRIEND_H
