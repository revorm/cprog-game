#include "environment.h"
#include <algorithm>

bool Environment::pick_up(Object* o) {
  std::vector<Object*>::iterator it =
      std::find(m_objects.begin(),m_objects.end(),o);
  if(it != m_objects.end()) {
    m_objects.erase(it);
    return true;
  }
  return false;
}

void Environment::drop(Object* o) {
  add_object(o);
}

void Environment::add_neighbor(Direction d, Environment* e) {
  m_neighbors[d] = e;
}

void Environment::add_object(Object* o) {
  m_objects.push_back(o);
}
