#include "sleven.h"

#include "../char/character.h"
#include "../obj/object.h"
#include "../obj/coffee.h"

#include "../gameengine.h"

#include <algorithm>
#include <sstream>

int Sleven::coffee_count = 0;

static bool isCoffee(Object* o) {
  return o->name().find("coffee") == 0;
}

void Sleven::interact(Character *c) {
  const static std::string coffee("coffee");
  std::stringstream s(coffee,std::ios_base::in);
  std::vector<Object*>::const_iterator it = std::find_if(c->inventory().begin(),c->inventory().end(),isCoffee);
  if(it == c->inventory().end()) {
    s << coffee_count++;

    Coffee* co = new Coffee(s.str());
    GameEngine::get()->add_to_game(s.str(),co);

    // drop coffee on floor...
    c->environment()->drop(co);
  }
}
