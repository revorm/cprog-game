#include "friend.h"
#include "player.h"

#include "../obj/idea.h"
#include "../env/outdoor.h"

#include <cstdlib>

void cprog_game::Friend::action() {
  if((m_count++ % m_stress_level) == 0) {
    const Environment::Direction_map m = environment()->directions();
    unsigned int r = rand() % m.size();
    Environment::Direction_map::const_iterator it = m.begin();
    while(r--) { ++it; }
    go(it->first);
  }
}

void cprog_game::Friend::interact(Character *c) {
  Player* p = dynamic_cast<Player*>(c);
  if(p) {
    Outdoor* e = dynamic_cast<Outdoor*>(environment());
    if(e) {
      say_to(p,"Here's an idea for your game!");
      e->put_item(m_idea);
    } else {
      say_to(p,"It's too windy here, you'll not understand it.");
    }
  }
}
