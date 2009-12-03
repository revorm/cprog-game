#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "../playercontroller.h"

class Player : public Character
{
public:
  Player(const std::string& name) : Character(name), m_controller(new PlayerController(this)) {}

  void inform(const std::string &s);

  void action();

private:
  friend class PlayerController;
  PlayerController* m_controller;
};

#endif // PLAYER_H
