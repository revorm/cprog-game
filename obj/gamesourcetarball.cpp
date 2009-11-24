#include "gamesourcetarball.h"
#include "../gameengine.h"

void GameSourceTarball::interact(Character* c) {
  std::ostream& os = GameEngine::get()->out();
  os << "You play the game on your laptop and estimate that it's " << value() << " fun" << std::endl;
}
