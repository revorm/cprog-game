#ifndef FRIEND_H
#define FRIEND_H

#include "character.h"

namespace cprog_game
{
  class Idea;
  
  class Friend : public Character
  {
  public:
    Friend(const std::string& name, Environment* start_env, Idea* i, const int stress) : Character(name,start_env), m_idea(i), m_stress_level(stress), m_count(0) {}
  
    void interact(Character *);
  
    void action();
  
  private:
    Idea* m_idea;
    int   m_stress_level;
    int   m_count;
  };
}

#endif // FRIEND_H
