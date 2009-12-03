#include "sleven.h"

#include "../char/character.h"
#include "../obj/object.h"
#include "../obj/coffee.h"

#include "../engine/gameengine.h"

#include <algorithm>
#include <sstream>

int Sleven::coffee_count = 0;

void Sleven::interact(Character *c) {
  const static std::string coffee("coffee");
  std::stringstream s(coffee,std::ios_base::in);
  Character::Inventory_t::const_iterator it = c->inventory().lower_bound(std::string("coffee"));
  if(it->first.find("coffee") != 0) {
    s << coffee_count++;

    Coffee* co = new Coffee(s.str());
    GameEngine::get()->add_to_game(s.str(),co);

    // drop coffee on floor...
    c->environment()->put_item(co);
  }
}
