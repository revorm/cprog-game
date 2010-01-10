#include "theescape.h"
#include "../engine/gameengine.h"
#include "../obj/apple.h"

#include <sstream>

int cprog_game::TheEscape::s_apple_counter(0);

void cprog_game::TheEscape::interact(Character *c) {
  const static std::string apple_name("apple");
  std::stringstream s;
  s << apple_name;
  s << s_apple_counter++;
  Apple* a = new Apple(s.str());
  GameEngine::get()->add_to_game(a);
  put_item(a);
}
