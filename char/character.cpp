#include "character.h"

#include "../gameengine.h"

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

void Character::pick_up(const std::string& name) {
  Object* o = m_current_environment->get_item(name);
  if(o != 0) {
    m_inventory.insert(std::make_pair(name,o));
  }
}

void Character::drop(const std::string& name) {
  Inventory_t::iterator it = m_inventory.find(name);
  if(it != m_inventory.end()) {
    m_current_environment->put_item(it->first,it->second);
    m_inventory.erase(it);
  }
}

std::pair<Character::Inventory_t::const_iterator,
    Character::Inventory_t::const_iterator>
    Character::inventory() const {
  return std::make_pair(m_inventory.begin(),m_inventory.end());
}

int Character::energy() const {
  return m_energy;
}

void Character::add_energy(int add) {
  m_energy += add;
  if(m_energy > START_ENERGY) {
    m_energy = START_ENERGY;
  }
}
