#include "playercontroller.h"
#include "engine/gameengine.h"
#include "char/player.h"

#include <sstream>

void PlayerController::PlayerCommands::drop(std::vector<std::string> v) {
  if(!v.size()) {
    m_player->inform("You dropped nothing. And nothing happend. Happy?");
    return;
  }
  if(m_player->drop(v[0])) {
    m_player->inform(v[0] + " got dropped.");
  } else {
    m_player->inform(v[0] + " can't be dropped. You sure you have it in your pocket?");
  }
}

void PlayerController::PlayerCommands::go(std::vector<std::string> v) {
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
    m_player->inform(v[0] + " is an unknown direction");
    return;
  }
  if(m_player->go(d)) {
    look(std::vector<std::string>());
  } else {
    m_player->inform("You can't go to " + v[0]);
  }
}

void PlayerController::PlayerCommands::help(std::vector<std::string> v) {
  m_player->inform(" go - Makes the player go in a direction, if an exit in that direction exists.");
  m_player->inform("Valid directions are: west, east, north and south.");
  m_player->inform(" help - This text.");
  m_player->inform(" look - don't remember what room you are in? Then this is for you.");
}

void PlayerController::PlayerCommands::look(std::vector<std::string> v) {
  Environment* env = m_player->environment();
  m_player->inform("You are in" + env->name());
  m_player->inform(env->description());
}

void PlayerController::PlayerCommands::pocket(std::vector<std::string> v) {
  if(m_player->inventory().size()) {
    std::ostringstream s;
    s << "You have ";
    for(Character::Inventory_t::const_iterator it = m_player->inventory().begin();
    it != m_player->inventory().end(); ++it) {
      s << it->first << " ";
    }
    s << "in your pocket";
    m_player->inform(s.str());
  } else {
    m_player->inform("Your pocket is empty. Go find some stuff!");
  }
}

void PlayerController::PlayerCommands::quit(std::vector<std::string> v) {
  GameEngine::get()->game_finished();
}

void PlayerController::PlayerCommands::take(std::vector<std::string> v) {
  if(!v.size()) {
    m_player->inform("No objects given. Don't you want to take something?");
    return;
  }
  if(m_player->pick_up(v[0])) {
    m_player->inform(v[0] + " has been picked up to your pocket.");
  } else {
    m_player->inform(v[0] + " could not be taken. Sure you are in the right room?");
  }
}

PlayerController::PlayerCommands::PlayerCommands(Player* p): m_player(p){}