#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <string>
#include <map>
#include <stdexcept>
#include <ostream>

class Object;
class Environment;
class Character;

class GameEngine
{
public:
  const static std::string IDEA_CONTAINER_NAME;
  const static int NUM_IDEAS_NEEDED;

  ~GameEngine();
  static GameEngine* get();

  void add_to_game(const std::string& name, Object* o);
  void add_to_game(const std::string& name, Character* c);
  void add_to_game(const std::string& name, Environment* e);

  void erase_and_free(const std::string& name, Object* o);
  void erase_and_free(const std::string& name, Character* o);
  void erase_and_free(const std::string& name, Environment* o);

  /*Object* resolve_obj(const std::string& name) const;
  Character* resolve_char(const std::string& name) const;
  Environment* resolve_env(const std::string& name) const;*/

  void game_finished();

private:
  void main_loop();
  void init();
  friend void run_game();
  GameEngine() { if(s_instance == 0) s_instance = this;
                 else throw std::logic_error(
                     "Already created an instance of GameEngine"); }

  static GameEngine* s_instance;
  std::multimap<std::string,Object*> m_objects;
  std::multimap<std::string,Character*> m_characters;
  std::multimap<std::string,Environment*> m_environments;
  bool m_running;

};

#endif // GAMEENGINE_H
