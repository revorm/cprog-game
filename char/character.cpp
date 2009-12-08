#include "character.h"

#include "../engine/gameengine.h"

const int Character::START_ENERGY = 100;

void Character::inform(const std::string &s) {}

Environment* Character::environment() const {
  return m_current_environment;
}

void Character::go(Environment::Direction d) {
  Environment* neighbor = m_current_environment->neighbor(d);
  if(neighbor) {
    m_current_environment->leave(this);
    m_current_environment = neighbor;
    m_current_environment->enter(this);
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
    m_current_environment->put_item(it->second);
    m_inventory.erase(it);
  }
}

const Character::Inventory_t& Character::inventory() const {
  return m_inventory;
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

void Character::say_to(Character *c, const std::string &message) const {
  c->inform(name() + std::string(": ") + message);
}
