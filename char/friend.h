#ifndef FRIEND_H
#define FRIEND_H

#include "character.h"

namespace cprog_game
{
  class Idea;
  
  class Friend : public Character
  {
  public:
    Friend(const std::string& name, Environment* start_env, Idea* i) : Character(name,start_env), m_idea(i) {}
  
    void interact(Character *);
  
    void action();
  
  private:
    Idea* m_idea;
  };
}

#endif // FRIEND_H
