#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "../playercontroller.h"

namespace cprog_game
{
  class Player : public Character
  {
  public:
    Player(const std::string& name, Environment* start_env) : Character(name,start_env), m_controller(new PlayerController(this)) {}
  
    ~Player() { delete m_controller; }
    
    PlayerController* controller();
  
    void inform(const std::string &s);
  
    void action();

    bool take(const std::string &name);
  
    void interact(Character *) {}
  
  private:
    PlayerController* m_controller;
  };
}

#endif // PLAYER_H
