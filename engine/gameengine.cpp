#include "gameengine.h"
#include <iostream>

#include "../char/character.h"
#include "../env/environment.h"
#include "../obj/object.h"

cprog_game::GameEngine* cprog_game::GameEngine::s_instance = 0;

cprog_game::GameEngine::~GameEngine() {
  for(ObjectContainer::const_iterator it =
      m_objects.begin(); it != m_objects.end(); ++it) {
    delete *it;
  }
  for(EnvironmentContainer::const_iterator it =
      m_environments.begin(); it != m_environments.end(); ++it) {
    delete *it;
  }
  for(CharacterContainer::const_iterator it =
      m_characters.begin(); it != m_characters.end(); ++it) {
    delete *it;
  }
}

cprog_game::GameEngine* cprog_game::GameEngine::get() {
  return s_instance != 0 ? s_instance :
      throw std::logic_error("GameEngine not initialized");
}

// void cprog_game::GameEngine::add_to_game(GameElement* g){
//   m_game_elements.push_back(g);
// }

// m_game_elements.push_back(GameElement* g){
//   
// }

void cprog_game::GameEngine::add_to_game(Object* o) {
  m_objects.push_back(o);
}

void cprog_game::GameEngine::add_to_game(Environment* e) {
  m_environments.push_back(e);
}

void cprog_game::GameEngine::add_to_game(Character* c) {
  m_characters.push_back(c);
}

void cprog_game::GameEngine::erase_and_free(Object *o) {
  for(ObjectContainer::iterator it = m_objects.begin(); it != m_objects.end(); ++it) {
    if(*it== o) {
      delete *it;
      m_objects.erase(it);
      return;
    }
  }
}

void cprog_game::GameEngine::main_loop() {
  init();
  m_running = true;
  while(m_running) {
    for(CharacterContainer::iterator it = m_characters.begin(); it != m_characters.end(); ++it) {
      (*it)->action();
    }
  }
}

void cprog_game::GameEngine::game_finished() {
  m_running = false;
}

bool cprog_game::GameEngine::interactive() const {
  return m_interactive;
}
