#include "examiner.h"
#include "../engine/gameengine.h"
#include "../obj/gamesourcetarball.h"
#include "../env/examineroffice.h"
#include "../env/fikaroom.h"

#include <sstream>
#include <cstdlib>

const int cprog_game::Examiner::FIKA_TIMEOUT = 4; // examiner hides in fika-room for 4 turns

cprog_game::Examiner::Examiner(
    const std::string& name, Environment* start_env) : Character(name,start_env), m_examiner_mood(BAD) {
}

void cprog_game::Examiner::action() {
  /*if(dynamic_cast<ExaminerOffice*>(m_current_environment)) {
    if((m_current_environment->characters().size() < 2) && rand() < (RAND_MAX/8) ) { // approx 12,5% probab.
      m_move_timer = 0;
      go(Environment::NORTH);
    }
  } else if(dynamic_cast<FikaRoom*>(m_current_environment)) {
    ++m_move_timer;
    if(m_move_timer >= FIKA_TIMEOUT) {
      go(Environment::SOUTH);
    }
  }*/
}

void cprog_game::Examiner::interact(Character *c) {
  say_to(c,"Are you done with your lab yet?");
  const Environment::Inventory_t& objs = environment()->objects();
  Environment::Inventory_t::const_iterator it = objs.lower_bound("game");
  if(it != objs.end() && it->first.substr(0,4) != "game") {
    it = objs.end();
  }

  if(it != objs.end()) {
    GameSourceTarball* g = dynamic_cast<GameSourceTarball*>(it->second);
    if(g) {
      say_to(c,"Let me look at it...");

      if(g->value() >= int(m_examiner_mood)) {
        say_to(c,"Well done! You get an E for effort...");
        GameEngine::get()->game_finished();
      } else {
        say_to(c,"Well that wasn't very good now was it FFFFFFF!");
        take(it->first);
      }
    }
  }
}

void cprog_game::Examiner::set_good_mood() {
  m_examiner_mood = GOOD;
}
