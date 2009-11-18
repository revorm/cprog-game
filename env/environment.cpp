#include "environment.h"
#include <algorithm>
#include <sstream>

const std::map<Environment::Direction,Environment*> Environment::directions() const {
  return m_neighbors;
}

Environment* Environment::neighbor(Direction d) const {
  std::map<Direction,Environment*>::const_iterator it = m_neighbors.find(d);
  if(it != m_neighbors.end()) {
    return it->second;
  } else {
    return 0;
  }
}

std::string Environment::description() const {
  static const char* exit_names[] = { "north", "south", "east", "west" };
  std::stringstream s(std::stringstream::in);
  s << m_description;
  s << "There are exits to the ";
  for(std::map<Direction,Environment*>::const_iterator it = m_neighbors.begin()
    ; it != m_neighbors.end(); ++it) {
    s << exit_names[unsigned(it->first)] << " ";
  }
  s << std::endl;
  return s.str();
}

void Environment::enter(Character* c) {
  m_characters.push_back(c);
}

void Environment::leave(Character* c) {
  std::vector<Character*>::iterator it =
      std::find(m_characters.begin(),m_characters.end(),c);
  if(it != m_characters.end()) {
    m_characters.erase(it);
  }
}

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
  m_objects.push_back(o);
}

void Environment::add_neighbor(Direction d, Environment* e) {
  m_neighbors[d] = e;
}
