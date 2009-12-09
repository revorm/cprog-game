#include "playercommands.h"
void PlayerCommands::quit(std::vector<std::string> v) {
  GameEngine::get()->game_finished();
}