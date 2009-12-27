#include "playercontroller.h"

#include <iostream>
#include <sstream>

PlayerController::PlayerController(Player* p) : m_commands(p), m_player(p) {
  m_translator["drop"]    = &PlayerController::PlayerCommands::drop;
  m_translator["go"]      = &PlayerController::PlayerCommands::go;
  m_translator["exit"]    = &PlayerController::PlayerCommands::quit;
  m_translator["help"]    = &PlayerController::PlayerCommands::help;
  m_translator["look"]    = &PlayerController::PlayerCommands::look;
  m_translator["pocket"]  = &PlayerController::PlayerCommands::pocket;
  m_translator["quit"]    = &PlayerController::PlayerCommands::quit;
  m_translator["take"]    = &PlayerController::PlayerCommands::take;
}
std::istream& PlayerController::in() {
  return std::cin;
}

std::ostream& PlayerController::out() {
  return std::cout;
}

PlayerController::PlayerCommands* PlayerController::commands() {
  return &m_commands;
}

void PlayerController::get_command() {
  std::string line, first_token, token;
  std::vector<std::string> tokens;
  out() << "€ ";
  std::getline(in(), line);
  std::istringstream stream(line);
  stream >> first_token;
  while(stream >> token)
    tokens.push_back(token);
  if(m_translator.find(first_token) != m_translator.end()) {
    (m_commands.*(m_translator[first_token]))(tokens);
  } else if(first_token.size()) {
    out() << first_token << ": command not found" << std::endl;
  }
}
