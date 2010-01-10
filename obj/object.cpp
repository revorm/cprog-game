#include "object.h"

int cprog_game::Object::value() const {
  return m_value;
}

int cprog_game::Object::weight() const {
  return m_weight;
}

std::string cprog_game::Object::description() const {
  return m_description;
}
