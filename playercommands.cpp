#include "playercontroller.h"
#include "engine/gameengine.h"

void PlayerController::PlayerCommands::quit(std::vector<std::string> v) {
  GameEngine::get()->game_finished();
}