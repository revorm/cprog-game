#include "sleven.h"

#include "../char/character.h"
#include "../obj/object.h"
#include "../obj/coffee.h"

#include "../engine/gameengine.h"

#include <algorithm>
#include <sstream>

int cprog_game::Sleven::coffee_count = 0;

void cprog_game::Sleven::interact(Character *c) {
  const static std::string coffee("coffee");
  std::stringstream s(coffee,std::ios_base::in);
  s << coffee_count++;

  Coffee* co = new Coffee(s.str());
  GameEngine::get()->add_to_game(s.str(),co);

  // drop coffee on floor...
  put_item(co);

}
