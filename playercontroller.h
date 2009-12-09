#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <ostream>
#include <map>
#include <vector>

#include "playercommands.h"

class Player;
class PlayerController
{
public:
  typedef void (PlayerCommands::*method) (std::vector<std::string>);
  
  std::map<std::string, method> m_translator;
  
  PlayerCommands m_commands;
  
  PlayerController(Player* p) : m_player(p) {
    m_translator["quit"] = &PlayerCommands::quit;
  }

  std::istream& in();
  std::ostream& out();
  

  void get_command();

private:
  Player* m_player;
};

#endif // PLAYERCONTROLLER_H
