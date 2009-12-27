#include "playercontroller.h"
#include "engine/gameengine.h"
#include "char/player.h"

#include <sstream>

void PlayerController::PlayerCommands::go(std::vector<std::string> v) {
  std::ostringstream s;
  if(!v.size()) {
    m_player->inform("No direction given. Where do you want to go?");
    return;
  }
  Environment::Direction d;
  if(v[0] == "east") {
    d = Environment::EAST;
  } else if(v[0] == "west") {
    d = Environment::WEST;
  } else if(v[0] == "north") {
    d = Environment::NORTH;
  } else if(v[0] == "south") {
    d = Environment::SOUTH;
  } else {
    s << v[0] << " is an unknown direction";
    m_player->inform(s.str());
    return;
  }
  if(m_player->go(d)) {
    look(std::vector<std::string>());
  } else {
    s << "You can't go to " << v[0];
    m_player->inform(s.str());
  }
}

void PlayerController::PlayerCommands::help(std::vector<std::string> v) {
  m_player->inform(" go - Makes the player go in a direction, if an exit in that direction exists.");
  m_player->inform("Valid directions are: west, east, north and south.");
  m_player->inform(" help - This text.");
  m_player->inform(" look - don't remember what room you are in? Then this is for you.");
}

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