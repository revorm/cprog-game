#include "environment.h"
#include <algorithm>
#include <sstream>

#include "../obj/object.h"
#include "../char/character.h"

const cprog_game::Environment::Direction_map cprog_game::Environment::directions() const {
  return m_neighbors;
}

cprog_game::Environment* cprog_game::Environment::neighbor(Direction d) const {
  std::map<Direction,Environment*>::const_iterator it = m_neighbors.find(d);
  return it != m_neighbors.end() ? it->second : NULL;
}

std::string cprog_game::Environment::description() const {
  static const char* exit_names[] = { "north", "south", "east", "west" };
  std::ostringstream s;
  s << m_description << std::endl;
  s << "There are exits to the ";
  for(Direction_map::const_iterator it = m_neighbors.begin()
    ; it != m_neighbors.end(); ++it) {
    s << exit_names[unsigned(it->first)] << " ";
  }
  s << std::endl;
  s << "Items: ";
  for(Inventory_t::const_iterator it = m_objects.begin()
    ; it != m_objects.end(); ++it) {
    s << it->first << " ";
  }
  s << std::endl;
  s << "Characters: ";
  for(std::vector<Character*>::const_iterator it = m_characters.begin(); it != m_characters.end(); ++it) {
    s << (*it)->name() << " ";
  }
  return s.str();
}

void cprog_game::Environment::enter(Character* c) {
  m_characters.push_back(c);
}

void cprog_game::Environment::leave(Character* c) {
  std::vector<Character*>::iterator it =
      std::find(m_characters.begin(),m_characters.end(),c);
  if(it != m_characters.end()) {
    m_characters.erase(it);
  }
}

cprog_game::Object* cprog_game::Environment::get_item(const std::string& name) {
  std::map<std::string,Object*>::iterator it = m_objects.find(name);
  if(it != m_objects.end()) {
    Object* o = it->second;
    m_objects.erase(it);
    return o;
  }
  return NULL;
}

void cprog_game::Environment::put_item(Object* o) {
  m_objects.insert(std::make_pair(o->name(),o));
}

const cprog_game::Environment::Inventory_t& cprog_game::Environment::objects() const {
  return m_objects;
}

void cprog_game::Environment::add_neighbor(Direction d, cprog_game::Environment* e) {
  m_neighbors[d] = e;
}

bool cprog_game::Environment::can_enter(Character * c) {
  return true;
}

const std::vector<cprog_game::Character*> cprog_game::Environment::characters() const {
  return m_characters;
}
