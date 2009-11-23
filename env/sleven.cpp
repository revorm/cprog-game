#include "sleven.h"

#include "../char/character.h"
#include "../obj/object.h"

#include <algorithm>

static bool isCoffee(Object* o) {
  return o->name() == "coffee";
}

void Sleven::interact(Character *c) {
  std::vector<Object*>::const_iterator it = std::find_if(c->inventory().begin(),c->inventory().end(),isCoffee);
  if(it == c->inventory().end()) {
    // insert coffee into inventory
  }
}
