#include "computerroom.h"

#include "../gameengine.h"
#include "../char/character.h"
#include "../obj/ideacontainer.h"
#include "../obj/gamesourcetarball.h"

void ComputerRoom::interact(Character* c) {
  Character::Inventory_t::const_iterator it = c->inventory().find(IdeaContainer::ITEM_NAME);

  if(it != c->inventory().end()) {
    GameSourceTarball* g = new GameSourceTarball(
        std::string("game"),it->second->value(),std::string("You think it's a great c++ game"));
    GameEngine::get()->add_to_game(g->name(),g);
    put_item(g);
  }
}
