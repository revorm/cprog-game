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
    void go(std::vector<std::string>);
    void help(std::vector<std::string>);
    void look(std::vector<std::string>);
    void quit(std::vector<std::string>);
    PlayerCommands(Player*);
  private:
    Player* m_player;
  };
  typedef void (PlayerCommands::*method) (std::vector<std::string>);

  PlayerController(Player*);

  std::istream& in();
  std::ostream& out();
  
  PlayerCommands* commands();
  
  void get_command();

private:
  PlayerCommands m_commands;
  Player* m_player;
  std::map<std::string, method> m_translator;
};

#endif // PLAYERCONTROLLER_H
