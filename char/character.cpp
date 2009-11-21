#include "character.h"

const int Character::START_ENERGY = 100;

Environment* Character::environment() const {
  return m_current_environment;
}

void Character::go(Environment::Direction d) {
  if(m_current_environment->neighbor(d)) {
    m_current_environment->leave(this);
    m_current_environment->neighbor(d)->enter(this);
  }
}

void Character::pick_up(Object* o) {
  if(m_current_environment->pick_up(o)) {
    m_inventory.push_back(o);
  }
}

void Character::drop(Object* o) {
  m_current_environment->drop(o);
}

const std::vector<Object*>& Character::inventory() const {
  return m_inventory;
}

int Character::energy() const {
  return m_energy;
}

void Character::add_energy(int add) {
  m_energy += add;
}
