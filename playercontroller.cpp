#include "playercontroller.h"

#include <iostream>
#include <sstream>

cprog_game::PlayerController::PlayerController(Player* p) : m_commands(p), m_player(p) {
  m_translator["drop"]    = &cprog_game::PlayerController::PlayerCommands::drop;
  m_translator["go"]      = &cprog_game::PlayerController::PlayerCommands::go;
  m_translator["exit"]    = &cprog_game::PlayerController::PlayerCommands::quit;
  m_translator["help"]    = &cprog_game::PlayerController::PlayerCommands::help;
  m_translator["look"]    = &cprog_game::PlayerController::PlayerCommands::look;
  m_translator["pocket"]  = &cprog_game::PlayerController::PlayerCommands::pocket;
  m_translator["quit"]    = &cprog_game::PlayerController::PlayerCommands::quit;
  m_translator["take"]    = &cprog_game::PlayerController::PlayerCommands::take;
}
std::istream& cprog_game::PlayerController::in() {
  return std::cin;
}

std::ostream& cprog_game::PlayerController::out() {
  return std::cout;
}

cprog_game::PlayerController::PlayerCommands* cprog_game::PlayerController::commands() {
  return &m_commands;
}

void cprog_game::PlayerController::get_command() {
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
