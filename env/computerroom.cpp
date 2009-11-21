#include "computerroom.h"

#include "../gameengine.h"
#include "../char/character.h"
#include "../obj/object.h"

#include <algorithm>

static bool find_idea_container(Object* o) {
  return o->name() == GameEngine::IDEA_CONTAINER_NAME;
}

void ComputerRoom::interact(Character* c) {
  std::vector<Object*>::const_iterator it = std::find_if(
      c->inventory().begin(),c->inventory().end(),find_idea_container);

  if(it != c->inventory().end()) {
    // TODO: create a source tarball with a value of it->value()
  }
}
