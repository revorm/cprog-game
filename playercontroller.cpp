#include "playercontroller.h"

#include <iostream>
#include <sstream>

cprog_game::PlayerController::PlayerController(Player* p) : m_commands(p,m_translator), m_player(p) {
  m_translator["drop"]    = std::make_pair(&cprog_game::PlayerController::PlayerCommands::drop,
                                           "drop [item]: Drop an item you have in your pocket");
  m_translator["go"]      = std::make_pair(&cprog_game::PlayerController::PlayerCommands::go,
                                           "go [direction]: Go to an adjacent room");
  m_translator["exit"]    = std::make_pair(&cprog_game::PlayerController::PlayerCommands::quit,
                                           "exit: Quit the game");
  m_translator["help"]    = std::make_pair(&cprog_game::PlayerController::PlayerCommands::help,
                                           "help: Print a help text");
  m_translator["look"]    = std::make_pair(&cprog_game::PlayerController::PlayerCommands::look,
                                           "look: Look around the room");
  m_translator["pocket"]  = std::make_pair(&cprog_game::PlayerController::PlayerCommands::pocket,
                                           "pocket: Look in your pocket");
  m_translator["quit"]    = std::make_pair(&cprog_game::PlayerController::PlayerCommands::quit,
                                           "quit: Quit the game");
  m_translator["take"]    = std::make_pair(&cprog_game::PlayerController::PlayerCommands::take,
                                           "take [item]: Pick up an item from the ground");
  m_translator["wait"]    = std::make_pair(&cprog_game::PlayerController::PlayerCommands::wait,
                                           "wait: Wait for a while");
  m_translator["talk"]    = std::make_pair(&cprog_game::PlayerController::PlayerCommands::talk,
                                           "talk [character]: Talk to another character");
  m_translator["use"]     = std::make_pair(&cprog_game::PlayerController::PlayerCommands::use,
                                           "use [item]: Use an item in your pocket");
  m_translator["search"]  = std::make_pair(&cprog_game::PlayerController::PlayerCommands::search,
                                           "search: Inspect the current room more closely");
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
    // call the function matching first_token on the object m_commands
    (m_commands.*(m_translator[first_token].first))(tokens);
  } else if(first_token.size()) {
    out() << first_token << ": command not found" << std::endl;
  }
}
