#include "outdoor.h"
#include "../engine/gameengine.h"
#include "../obj/object.h"

void Outdoor::put_item(Object *o) {
  GameEngine::get()->erase_and_free(o->name(),o);
}
