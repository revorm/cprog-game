#include "examiner.h"
#include "../engine/gameengine.h"
#include "../obj/gamesourcetarball.h"
#include "../env/examineroffice.h"
#include "../env/fikaroom.h"

#include <sstream>
#include <cstdlib>

const int cprog_game::Examiner::FIKA_TIMEOUT = 4; // examiner hides in fika-room for 4 turns

cprog_game::Examiner::Examiner(
    const std::string& name, Environment* start_env) : Character(name,start_env), m_examining(false), m_should_exit(false), m_examiner_mood(BAD) {
}

void cprog_game::Examiner::action() {
  if(dynamic_cast<ExaminerOffice*>(m_current_environment)) {
    if(rand() < (RAND_MAX/8) ) { // approx 12,5% probab.
      m_move_timer = 0;
      go(Environment::NORTH);
    }
  } else if(dynamic_cast<FikaRoom*>(m_current_environment)) {
    ++m_move_timer;
    if(m_move_timer >= FIKA_TIMEOUT) {
      go(Environment::SOUTH);
    }
  }
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
      if(value >= int(m_examiner_mood)) {
        m_should_exit = true;
      }
    }
  }
}

void cprog_game::Examiner::set_good_mood() {
  m_examiner_mood = GOOD;
}
