#ifndef ORACLE_H
#define ORACLE_H

#include "character.h"

namespace cprog_game
{
  class Oracle : public Character
  {
  public:
    Oracle(const std::string& name, Environment* start_env) : Character(name,start_env) {}
  
    void action();
  
    void interact(Character *);
  };
}

#endif // ORACLE_H
