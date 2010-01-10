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
    class PlayerCommands;

    typedef void (PlayerCommands::*method) (const std::vector<std::string>&);
    typedef std::map<std::string, std::pair<method,std::string> > translator_t;

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
      void talk(const std::vector<std::string>&);
      void use(const std::vector<std::string>&);
      void search(const std::vector<std::string>&);
      PlayerCommands(Player*, const translator_t&);
    private:
      Player* m_player;
      int m_wait_counter;
      const translator_t& m_translator;
    };

  
    PlayerController(Player*);
  
    std::istream& in();
    std::ostream& out();
    
    PlayerCommands* commands();
    
    void get_command();
  
  private:
    translator_t m_translator;
    PlayerCommands m_commands;
    Player* m_player;
  };
}

#endif // PLAYERCONTROLLER_H
