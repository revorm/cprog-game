#ifndef ORACLE_H
#define ORACLE_H

#include "character.h"

class Oracle : public Character
{
public:
  Oracle(const std::string& name) : Character(name) {}

  void action();

  void interact(Character *);
};

#endif // ORACLE_H
