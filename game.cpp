#include <iostream>

#include "gameengine.h"
#include "obj/container.h"
#include "char/character.h"
#include "env/environment.h"

#include "obj/ideacontainer.h"

void run_game() {
  GameEngine g;

  std::string n("nisse");
  GameEngine::add_to_game(n,new IdeaContainer(n));
}

int main(int argc, char **argv) {
  run_game();
  return 0;
}
