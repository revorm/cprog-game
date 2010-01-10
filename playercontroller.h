#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <ostream>
#include <map>
#include <vector>

namespace cprog_game
{
  class Player;
  class PlayerController
  {
  public:
    class PlayerCommands {
    public:
      void drop(const std::vector<std::string>&);
      void go(const std::vector<std::string>&);
      void help(const std::vector<std::string>&);
      void look(const std::vector<std::string>&);
      void pocket(const std::vector<std::string>&);
      void quit(const std::vector<std::string>&);
      void take(const std::vector<std::string>&);
      void wait(const std::vector<std::string>&);
      PlayerCommands(Player*);
    private:
      Player* m_player;
      int m_wait_counter;
    };
    typedef void (PlayerCommands::*method) (const std::vector<std::string>&);
  
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
}

#endif // PLAYERCONTROLLER_H
