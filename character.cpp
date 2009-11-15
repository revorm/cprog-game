#include "character.h"

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
