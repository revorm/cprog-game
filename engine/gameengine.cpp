#include "gameengine.h"

#include "../char/character.h"
#include "../env/environment.h"
#include "../obj/object.h"

#include <cstdlib>

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
  m_objects.insert(std::make_pair(name,o));
}

void GameEngine::add_to_game(const std::string& name, Environment* e) {
  m_environments.insert(std::make_pair(name,e));
}

void GameEngine::add_to_game(const std::string& name, Character* c) {
  m_characters.insert(std::make_pair(name,c));
}

void GameEngine::erase_and_free(const std::string &name, Object *o) {
  typedef std::multimap<std::string,Object*> objmap;
  std::pair<objmap::iterator,objmap::iterator> p = m_objects.equal_range(name);
  for(objmap::iterator it = p.first; it != p.second; ++it) {
    if(it->second == o) {
      m_objects.erase(it);
      return;
    }
  }
}

Object* GameEngine::resolve_obj(const std::string &name) const {
  ObjectContainer::const_iterator it = m_objects.find(name);
  if(it != m_objects.end()) {
    return it->second;
  }
  return 0;
}

void GameEngine::main_loop() {
  init();
  while(m_running) {
    for(CharacterContainer::const_iterator it = m_characters.begin(); it != m_characters.end(); ++it) {
      it->second->action();
    }
  }
}

void GameEngine::game_finished() {
  m_running = false;
}

