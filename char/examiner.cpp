#include "examiner.h"
#include "../engine/gameengine.h"
#include "../obj/gamesourcetarball.h"

#include <sstream>

const int Examiner::EXAMINER_MOOD = 2;

void Examiner::action() {
}

void Examiner::interact(Character *c) {
  Object* o = environment()->get_item("game");
  GameSourceTarball* g = dynamic_cast<GameSourceTarball*>(o);
  if(g) {
    m_examining = true;
    g->interact(this);
    m_examining = false;
  }
}

void Examiner::inform(const std::string &s) {
  if(m_examining && s.find("You play the game")) {
    size_t pos = s.find_first_of("0123456789");
    std::istringstream iss(s.substr(pos));
    int value;
    if(iss >> value) {
      if(value >= EXAMINER_MOOD) {
        GameEngine::get()->game_finished();
      }
    }
  }
}
