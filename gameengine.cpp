#include "gameengine.h"

#include "env/environment.h"
#include "char/character.h"
#include "obj/object.h"

const std::string GameEngine::IDEA_CONTAINER_NAME("idea_bag");
const int GameEngine::NUM_IDEAS_NEEDED = 4;

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

GameEngine* GameEngine::get() {
  return s_instance != 0 ? s_instance :
      throw std::logic_error("GameEngine not initialized");
}

void GameEngine::add_to_game(const std::string& name, Object* o) {
  m_objects[name] = o;
}

void GameEngine::add_to_game(const std::string& name, Environment* e) {
  m_environments[name] = e;
}

void GameEngine::add_to_game(const std::string& name, Character* c) {
  m_characters[name] = c;
}

Object* GameEngine::resolve_obj(const std::string& name) const {
  std::map<std::string,Object*>::const_iterator it = m_objects.find(name);
  if(it != m_objects.end()) {
    return it->second;
  }
  return 0;
}

Environment* GameEngine::resolve_env(const std::string& name) const {
  std::map<std::string,Environment*>::const_iterator it = m_environments.find(name);
  if(it != m_environments.end()) {
    return it->second;
  }
  return 0;
}

Character* GameEngine::resolve_char(const std::string& name) const {
  std::map<std::string,Character*>::const_iterator it = m_characters.find(name);
  if(it != m_characters.end()) {
    return it->second;
  }
  return 0;
}
