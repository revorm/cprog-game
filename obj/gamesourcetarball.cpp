#include "gamesourcetarball.h"
#include "../engine/gameengine.h"
#include "../char/character.h"

#include <sstream>

const std::string GameSourceTarball::ITEM_NAME("game");

void GameSourceTarball::interact(Character* c) {
  std::ostringstream ss;
  ss << "You play the game on your laptop and estimate that it's " << value() << " fun";
  c->inform(ss.str());
}
