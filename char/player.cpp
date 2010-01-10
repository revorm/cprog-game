#include "player.h"
#include "../playercontroller.h"
#include "../obj/object.h"

#include <iostream>

void cprog_game::Player::inform(const std::string &s) {
  m_controller->out() << s << std::endl;
}

void cprog_game::Player::action() {
  m_controller->get_command();
}


cprog_game::PlayerController* cprog_game::Player::controller() {
  return m_controller;
}