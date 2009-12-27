#include "playercontroller.h"
#include "engine/gameengine.h"
#include "char/player.h"

#include <sstream>

void PlayerController::PlayerCommands::look(std::vector<std::string> v) {
  std::ostringstream s;
  Environment* env = m_player->environment();
  s << "You are in " << env->name() << std::endl;
  s << env->description();
  m_player->inform(s.str());
}

void PlayerController::PlayerCommands::quit(std::vector<std::string> v) {
  GameEngine::get()->game_finished();
}

PlayerController::PlayerCommands::PlayerCommands(Player* p): m_player(p){}