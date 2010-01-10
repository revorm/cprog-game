#include "character.h"

#include "../engine/gameengine.h"

const int cprog_game::Character::START_ENERGY = 100;

void cprog_game::Character::inform(const std::string &s) {}

cprog_game::Environment* cprog_game::Character::environment() const {
  return m_current_environment;
}

bool cprog_game::Character::go(Environment::Direction d) {
  Environment* neighbor = m_current_environment->neighbor(d);
  if(neighbor && neighbor->can_enter(this)) {
    m_current_environment->leave(this);
    m_current_environment = neighbor;
    m_current_environment->enter(this);
  } else {
    return false;
  }
  return neighbor;
}

bool cprog_game::Character::take(const std::string& name) {
  Object* o = m_current_environment->get_item(name);
  if(o) {
    m_inventory.insert(std::make_pair(name,o));
  }
  return o;
}

bool cprog_game::Character::drop(const std::string& name) {
  Inventory_t::iterator it = m_inventory.find(name);
  bool b;
  if((b = it != m_inventory.end())) {
    m_current_environment->put_item(it->second);
    m_inventory.erase(it);
  }
  return b;
}

const cprog_game::Character::Inventory_t& cprog_game::Character::inventory() const {
  return m_inventory;
}

int cprog_game::Character::energy() const {
  return m_energy;
}

void cprog_game::Character::add_energy(int add) {
  m_energy += add;
  if(m_energy > START_ENERGY) {
    m_energy = START_ENERGY;
  }
}

void cprog_game::Character::say_to(Character *c, const std::string &message) const {
  c->inform(name() + std::string(": ") + message);
}
