#include <iostream>

#include "engine/gameengine.h"
#include "obj/container.h"
#include "char/character.h"
#include "env/environment.h"

#include "obj/ideacontainer.h"

namespace cprog_game
{
  void run_game(bool interactive) {
    GameEngine g;
    g.main_loop(interactive);
  }
}

int main(int argc, char **argv) {
  using namespace cprog_game;
  std::ios_base::sync_with_stdio(false);
  bool interactive = true;
  if(argc > 1 && argv[1][0] == 'a') {
    interactive = false;
  }
  run_game(interactive);
  return 0;
}
