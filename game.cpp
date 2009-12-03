#include <iostream>

#include "engine/gameengine.h"
#include "obj/container.h"
#include "char/character.h"
#include "env/environment.h"

#include "obj/ideacontainer.h"

void run_game() {
  GameEngine g;
  g.main_loop();
}

int main(int argc, char **argv) {
  std::ios_base::sync_with_stdio(false);
  run_game();
  return 0;
}
