#include "object.h"

int Object::value() const {
  return m_value;
}

int Object::weight() const {
  return m_weight;
}

std::string Object::description() const {
  return m_description;
}
