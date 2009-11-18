#include "container.h"
#include "../env/environment.h"
#include "../char/character.h"

#include <numeric>
#include <algorithm>
#include <functional>

static int weight_op(int weight, Object* o) {
  return weight + o->weight();
}

static int value_op(int value, Object* o) {
  return value + o->value();
}

int Container::weight() const {
  return std::accumulate(m_contents.begin(),m_contents.end(),m_weight,weight_op);
}

int Container::value() const {
  return std::accumulate(m_contents.begin(),m_contents.end(),m_value,value_op);
}

bool Container::add(Object* o) {
  if(o->weight() + weight() <= max_weight()) {
    m_contents.push_back(o);
    return true;
  }
  return false;
}

bool Container::remove(Object* o) {
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
void Container::interact(Character* c) {
  std::for_each(m_contents.begin(),m_contents.end(),
                std::bind1st(std::mem_fun(&Environment::drop),c->environment()));
  m_contents.clear();
}

int Container::max_weight() const {
  return m_max_weight;
}
