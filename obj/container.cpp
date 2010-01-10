#include "container.h"
#include "../env/environment.h"
#include "../char/character.h"

#include <numeric>
#include <algorithm>
#include <functional>

static int weight_op(int weight, cprog_game::Object* o) {
  return weight + o->weight();
}

static int value_op(int value, cprog_game::Object* o) {
  return value + o->value();
}

int cprog_game::Container::weight() const {
  return std::accumulate(m_contents.begin(),m_contents.end(),m_weight,weight_op);
}

int cprog_game::Container::value() const {
  return std::accumulate(m_contents.begin(),m_contents.end(),m_value,value_op);
}

bool cprog_game::Container::add(Object* o) {
  if(o->weight() + weight() <= max_weight()) {
    m_contents.push_back(o);
    return true;
  }
  return false;
}

bool cprog_game::Container::remove(Object* o) {
  std::vector<Object*>::iterator it = std::find(m_contents.begin(),m_contents.end(),o);
  if(it != m_contents.end()) {
    m_contents.erase(it);
    return true;
  }
  return false;
}

/* Interacting a character and a container will empty the container
  at the character's feet
 */
void cprog_game::Container::interact(Character* c) {
  std::for_each(m_contents.begin(),m_contents.end(),
                std::bind1st(std::mem_fun(&Environment::put_item),c->environment()));
  m_contents.clear();
}

int cprog_game::Container::max_weight() const {
  return m_max_weight;
}
