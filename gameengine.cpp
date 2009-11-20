#include "gameengine.h"

#include "env/environment.h"
#include "char/character.h"
#include "obj/object.h"

GameEngine* GameEngine::s_instance = 0;

GameEngine::~GameEngine() {
  for(std::map<std::string,Object*>::const_iterator it =
      m_objects.begin(); it != m_objects.end(); ++it) {
    delete it->second;
  }
  for(std::map<std::string,Environment*>::const_iterator it =
      m_environments.begin(); it != m_environments.end(); ++it) {
    delete it->second;
  }
  for(std::map<std::string,Character*>::const_iterator it =
      m_characters.begin(); it != m_characters.end(); ++it) {
    delete it->second;
  }
}

void GameEngine::add_to_game(const std::string& name, Object* o) {
  s_instance->m_objects[name] = o;
}

void GameEngine::add_to_game(const std::string& name, Environment* e) {
  s_instance->m_environments[name] = e;
}

void GameEngine::add_to_game(const std::string& name, Character* c) {
  s_instance->m_characters[name] = c;
}

Object* GameEngine::resolve_obj(const std::string& name) {
  std::map<std::string,Object*>::const_iterator it = s_instance->m_objects.find(name);
  if(it != s_instance->m_objects.end()) {
    return it->second;
  }
  return 0;
}

Environment* GameEngine::resolve_env(const std::string& name) {
  std::map<std::string,Environment*>::const_iterator it = s_instance->m_environments.find(name);
  if(it != s_instance->m_environments.end()) {
    return it->second;
  }
  return 0;
}

Character* GameEngine::resolve_char(const std::string& name) {
  std::map<std::string,Character*>::const_iterator it = s_instance->m_characters.find(name);
  if(it != s_instance->m_characters.end()) {
    return it->second;
  }
  return 0;
}
