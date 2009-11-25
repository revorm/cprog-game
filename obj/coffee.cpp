#include "coffee.h"
#include "../char/character.h"

#include "../gameengine.h"

#include <sstream>

const int Coffee::WEIGHT = 2;
const int Coffee::VALUE = 4;

const std::string Coffee::DESCRIPTION("A large cup of coffee, with a small amount of milk in it, it smells lovely.");

void Coffee::interact(Character* c) {
  std::ostringstream ss;
  if(value() > 0) {
    c->add_energy(50);
    --m_value;
    ss << "You feel refreshed" << std::endl;
  } else {
    ss << "The coffee cup is empty, you should throw it away" << std::endl;
  }
  c->inform(ss.str());
}
