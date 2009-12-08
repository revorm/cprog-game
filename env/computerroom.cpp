#include "computerroom.h"

#include "../engine/gameengine.h"
#include "../char/character.h"
#include "../char/player.h"
#include "../obj/ideacontainer.h"
#include "../obj/gamesourcetarball.h"

void ComputerRoom::interact(Character* c) {
  if(!dynamic_cast<Player*>(c)) {
    return;
  }

  Object* o = GameEngine::get()->resolve_obj(GameSourceTarball::ITEM_NAME);

  if(!o) {
    if(c->energy() > 80) {
      c->inform("You sit down an hack together a game in c++");
      Character::Inventory_t::const_iterator it = c->inventory().find(IdeaContainer::ITEM_NAME);
      if(it != c->inventory().end()) {
        GameSourceTarball* g = new GameSourceTarball(
            it->second->value(),"You think it's a great c++ game");
        GameEngine::get()->add_to_game(g->name(),g);
        put_item(g);
      } else {
        c->inform("You don't have an idea container");
      }
    } else {
      c->inform("You are too tired to code anything, maybe you should find"
                            " something with caffeine in it.");
    }
  }
}
