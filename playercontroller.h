#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <ostream>

class Player;

class PlayerController
{
public:
  PlayerController(Player* p) : m_player(p) {}

  std::ostream& out();

  void get_command();

private:
  Player* m_player;
};

#endif // PLAYERCONTROLLER_H
