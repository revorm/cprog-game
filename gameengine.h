#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <string>
#include <map>

class Object;
class Environment;
class Character;

class GameEngine
{
public:

  ~GameEngine();

  static void add_to_game(const std::string& name, Object* o);
  static void add_to_game(const std::string& name, Character* c);
  static void add_to_game(const std::string& name, Environment* e);

  static Object* resolve_obj(const std::string& name);
  static Character* resolve_char(const std::string& name);
  static Environment* resolve_env(const std::string& name);
private:
  friend void run_game();
  GameEngine() { s_instance = this; }
  static GameEngine* s_instance;
  std::map<std::string,Object*> m_objects;
  std::map<std::string,Character*> m_characters;
  std::map<std::string,Environment*> m_environments;

};

#endif // GAMEENGINE_H
