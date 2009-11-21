#include "coffee.h"
#include "../char/character.h"

const int Coffee::WEIGHT = 2;
const int Coffee::VALUE = 4;

void Coffee::interact(Character* c) {
    if(value() > 0) {
      c->add_energy(50);
      --m_value;
    }
  }
