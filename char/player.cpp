#include "player.h"
#include "../playercontroller.h"
#include "../obj/object.h"

#include <iostream>

void Player::inform(const std::string &s) {
  m_controller->out() << s << std::endl;
}

void Player::action() {
  m_controller->get_command();
}
