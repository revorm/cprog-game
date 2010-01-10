#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <string>
#include <vector>
#include <stdexcept>
#include <ostream>

namespace cprog_game
{
  class Character;
  class Environment;
  class Object;
  
  class GameEngine
  {
  public:

    typedef std::vector<Character*> CharacterContainer;
    typedef std::vector<Environment*> EnvironmentContainer;
    typedef std::vector<Object*> ObjectContainer;

    ~GameEngine();
    static GameEngine* get();

    void add_to_game(Character* c);
    void add_to_game(Environment* e);
    void add_to_game(Object* o);

    void erase_and_free(Object *o);

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
