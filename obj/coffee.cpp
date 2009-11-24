#include "coffee.h"
#include "../char/character.h"

#include "../gameengine.h"

const int Coffee::WEIGHT = 2;
const int Coffee::VALUE = 4;

const std::string Coffee::DESCRIPTION("A large cup of coffee, with a small amount of milk in it, it smells lovely.");

void Coffee::interact(Character* c) {
  if(value() > 0) {
    c->add_energy(50);
    --m_value;
    GameEngine::get()->out() << "You feel refreshed" << std::endl;
  } else {
    GameEngine::get()->out() << "The coffee cup is empty, you should throw it away" << std::endl;
  }
}
