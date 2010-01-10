#include "friend.h"
#include "player.h"

#include "../obj/idea.h"
#include "../env/outdoor.h"

#include <cstdlib>
#include <algorithm>

void cprog_game::Friend::action() {
  if((m_count++ % m_stress_level) == 0) {
    const Environment::Direction_map m = environment()->directions();
    unsigned int r = rand() % m.size();
    Environment::Direction_map::const_iterator it = m.begin();
    while(r--) { ++it; }
    go(it->first);
    if(environment()->characters().size() > 1){
      // Never talk to the player, the player talk to you.
      if(!dynamic_cast<Player*>(environment()->characters()[0])){
        interact(environment()->characters()[0]);
      }
    }
  }
}

void cprog_game::Friend::interact(Character *c) {
  Friend* f = dynamic_cast<Friend*>(c);  
  Player* p = dynamic_cast<Player*>(c);
  Outdoor* o = dynamic_cast<Outdoor*>(environment());
  
  if(m_idea) {
    if(!o) {
      if(p) {
        say_to(p,"Here's an idea for your game!");
        environment()->put_item(m_idea);
        m_idea = NULL;
      } else if(f) {
        say_to(f, "Let's switch ideas. I don't want mine any more.");
        std::swap(m_idea, f->m_idea);
      }
    } else {
      if(p)
      {
        say_to(p,"It's too windy here, you'll not understand it.");
      }
    }
  }
}
