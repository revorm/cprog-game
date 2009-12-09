#include "playercontroller.h"

#include <iostream>
#include <sstream>

std::istream& PlayerController::in() {
  return std::cin;
}

std::ostream& PlayerController::out() {
  return std::cout;
}

void PlayerController::get_command() {
  std::string line, first_token, token;
  std::vector<std::string> tokens;
  std::getline(in(), line);
  std::istringstream stream(line);
  stream >> first_token;
  while(stream >> token)
    tokens.push_back(token);
  if(m_translator.find(first_token) != m_translator.end()) {
    (m_commands.*(m_translator[first_token]))(tokens);
  }
}
