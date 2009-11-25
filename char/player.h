#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class PlayerController;

class Player : public Character
{
public:
  Player(const std::string& name, PlayerController* p) : Character(name), m_controller(p) {}

  void inform(const std::string &s);

  void action();

private:
  friend class PlayerController;
  PlayerController* m_controller;
};

#endif // PLAYER_H