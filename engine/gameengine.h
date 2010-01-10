#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <string>
#include <map>
#include <stdexcept>
#include <ostream>

namespace cprog_game
{
  class Object;
  class Environment;
  class Character;
  
  class GameEngine
  {
  public:

    typedef std::multimap<std::string,Object*> ObjectContainer;
    typedef std::multimap<std::string,Character*> CharacterContainer;
    typedef std::multimap<std::string,Environment*> EnvironmentContainer;

    ~GameEngine();
    static GameEngine* get();

    void add_to_game(const std::string& name, Object* o);
    void add_to_game(const std::string& name, Character* c);
    void add_to_game(const std::string& name, Environment* e);

    void erase_and_free(const std::string& name, Object* o);
    void erase_and_free(const std::string& name, Character* o);
    void erase_and_free(const std::string& name, Environment* o);

    Object* resolve_obj(const std::string& name) const;
    Character* resolve_char(const std::string& name) const;
    Environment* resolve_env(const std::string& name) const;

    void game_finished();

  private:
    void main_loop(bool interactive);
    void init(bool interactive);
    friend void cprog_game::run_game(bool);
    GameEngine() { if(s_instance == 0) s_instance = this;
                   else throw std::logic_error(
                       "Already created an instance of GameEngine"); }

    static GameEngine* s_instance;
    ObjectContainer m_objects;
    CharacterContainer m_characters;
    EnvironmentContainer m_environments;
    bool m_running;

  };
} /* cprog_game */ 

#endif // GAMEENGINE_H
