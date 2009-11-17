#ifndef TROLL_H
#define TROLL_H

#include <string>
#include "character.h"

class Troll : public Character
{
public:
  Troll(const std::string& name) : Character(std::string("Troll"),name) {}
  void action();
  void talk_to(Character* c);
};

#endif // TROLL_H
