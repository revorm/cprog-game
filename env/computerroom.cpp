#include "computerroom.h"

#include "../engine/gameengine.h"
#include "../char/character.h"
#include "../char/player.h"
#include "../obj/ideacontainer.h"
#include "../obj/gamesourcetarball.h"

#include  <sstream>

int cprog_game::ComputerRoom::s_tarball_count(0);

void cprog_game::ComputerRoom::interact(Character* c) {
  const static std::string name("game");
  if(!dynamic_cast<Player*>(c)) {
    return;
  }
  if(c->energy() > 80) {
    std::stringstream s(name,std::ios_base::in);
    s << s_tarball_count++;

    c->inform("You sit down an hack together a game in c++");
    Character::Inventory_t::const_iterator it = c->inventory().find(IdeaContainer::ITEM_NAME);
    if(it != c->inventory().end()) {
      GameSourceTarball* g = new GameSourceTarball(
          s.str(),"You think it's a great c++ game",
          it->second->value());
      GameEngine::get()->add_to_game(g);
      put_item(g);
    } else {
      c->inform("You don't have an idea container");
    }
  } else {
    c->inform("You are too tired to code anything, maybe you should find"
                          " something with caffeine in it.");
  }
}

