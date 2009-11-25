#include "gameengine.h"

#include "env/environment.h"
#include "char/character.h"
#include "obj/object.h"

#include <cstdlib>

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


void GameEngine::main_loop() {
  init();
  m_running = true;
  while(m_running) {
    // foreach char do char->action()
  }
}

void GameEngine::game_finished() {
  m_running = false;
}

void GameEngine::init() {
  srand(unsigned(time(NULL)));
}
