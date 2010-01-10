#include "theescape.h"
#include "../engine/gameengine.h"
#include "../obj/apple.h"

#include <sstream>

int cprog_game::TheEscape::s_apple_counter(0);

void cprog_game::TheEscape::interact(Character *c) {
  const static std::string apple_name("apple");
  std::stringstream s(apple_name,std::ios_base::in);
  s << s_apple_counter++;
  Apple* a = new Apple(s.str());
  GameEngine::get()->add_to_game(a->name(),a);
  put_item(a);
}
