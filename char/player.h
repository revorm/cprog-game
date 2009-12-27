#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "../playercontroller.h"

class Player : public Character
{
public:
  Player(const std::string& name, Environment* start_env) : Character(name,start_env), m_controller(new PlayerController(this)) {}

  ~Player() { delete m_controller; }
  
  PlayerController* controller();

  void inform(const std::string &s);

  void action();

  void interact(Character *) {}

private:
  friend class PlayerController;
  PlayerController* m_controller;
};

#endif // PLAYER_H
