#include "playercontroller.h"
#include "engine/gameengine.h"
#include "char/player.h"

#include <sstream>

void cprog_game::PlayerController::PlayerCommands::drop(const std::vector<std::string>& v) {
  m_wait_counter = 0; // no more waiting
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

void cprog_game::PlayerController::PlayerCommands::go(const std::vector<std::string>& v) {
  m_wait_counter = 0; // no more waiting
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

void cprog_game::PlayerController::PlayerCommands::help(const std::vector<std::string>& v) {
  m_player->inform(" go - Makes the player go in a direction, if an exit in that direction exists.");
  m_player->inform("Valid directions are: west, east, north and south.");
  m_player->inform(" help - This text.");
  m_player->inform(" look - don't remember what room you are in? Then this is for you.");
  m_player->action(); // Help isn't itself an action
}

void cprog_game::PlayerController::PlayerCommands::look(const std::vector<std::string>& v) {
  Environment* env = m_player->environment();
  m_player->inform("You are in " + env->name());
  m_player->inform(env->description());
  m_player->action(); // Look isn't itself an action
}

void cprog_game::PlayerController::PlayerCommands::pocket(const std::vector<std::string>& v) {
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
  m_player->action(); // Pocket isn't itself an action
}

void cprog_game::PlayerController::PlayerCommands::quit(const std::vector<std::string>& v) {
  GameEngine::get()->game_finished();
}

void cprog_game::PlayerController::PlayerCommands::take(const std::vector<std::string>& v) {
  m_wait_counter = 0; // no more waiting
  if(!v.size()) {
    m_player->inform("No objects given. Don't you want to take something?");
    return;
  }
  if(m_player->take(v[0])) {
    m_player->inform(v[0] + " has been picked up to your pocket.");
  } else {
    m_player->inform(v[0] + " could not be taken. Sure you are in the right room?");
  }
}

void cprog_game::PlayerController::PlayerCommands::wait(const std::vector<std::string>& v) {
  switch(m_wait_counter)
  {
    case 0: m_player->inform("You take a well needed break");
      break;
    case 1: m_player->inform("You extend your well needed break");
      break;
    case 2: m_player->inform("You are a bit lazy");
      break;
    case 3: m_player->inform("You are really lazy");
      break;
    case 4: m_player->inform("You sing a song");
      break;
    case 5: m_player->inform("You are a bit sleepy");
      break;
      case 6: m_player->inform("Your sleepiness got so big that instead of doing something (anything at all actually) you instead fell asleep.");
      m_player->inform("Sleeping at school? Not cool.");
      m_player->inform("Neither thinks the guards walking around school at midnight, who walks you out.");
      m_player->inform("While there you realize you have no card to get in at the now locked school so you go home and forget everything about finishing a game in c++.");
      m_player->inform("And that's the end of your journey.\n");
      m_player->inform("Don't stop believin'");
      m_player->inform("Hold on to the feelin'");
      m_player->inform("The end");
      GameEngine::get()->game_finished();
  }
  m_wait_counter++;
}

cprog_game::PlayerController::PlayerCommands::PlayerCommands(Player* p): m_player(p){
  m_wait_counter = 0;
}
