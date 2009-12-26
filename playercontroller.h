#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <ostream>
#include <map>
#include <vector>


class Player;
class PlayerController
{
public:
  class PlayerCommands {
  public:
    void quit(std::vector<std::string>);
  };
  typedef void (PlayerCommands::*method) (std::vector<std::string>);
  
  std::map<std::string, method> m_translator;
  
  PlayerCommands m_commands;
  
  PlayerController(Player*);

  std::istream& in();
  std::ostream& out();
  

  void get_command();

private:
  Player* m_player;
};

#endif // PLAYERCONTROLLER_H
