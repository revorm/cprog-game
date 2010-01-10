#include "examiner.h"
#include "../engine/gameengine.h"
#include "../obj/gamesourcetarball.h"

#include <sstream>

const int cprog_game::Examiner::EXAMINER_MOOD = 2;

void cprog_game::Examiner::action() {
}

void cprog_game::Examiner::interact(Character *c) {
  say_to(c,"Are you done with your lab yet?");
  Object* o = environment()->get_item("game");
  GameSourceTarball* g = dynamic_cast<GameSourceTarball*>(o);
  if(g) {
    say_to(c,"Let me look at it...");
    m_examining = true;
    g->interact(this);
    m_examining = false;

    if(m_should_exit) {
      say_to(c,"Well done! You get an E for effort...");
      GameEngine::get()->game_finished();
    }
  }
}

void cprog_game::Examiner::inform(const std::string &s) {
  if(m_examining && s.find("You play the game")) {
    size_t pos = s.find_first_of("0123456789");
    std::istringstream iss(s.substr(pos));
    int value;
    if(iss >> value) {
      if(value >= EXAMINER_MOOD) {
        m_should_exit = true;
      }
    }
  }
}
