#include "ideacontainer.h"

#include "idea.h"

#include <sstream>

const std::string cprog_game::IdeaContainer::ITEM_NAME("ideabag");

int cprog_game::IdeaContainer::value() const {
  int accum = 0;
  for(std::vector<Object*>::const_iterator it = m_contents.begin(); it != m_contents.end(); ++it) {
    Idea* i = dynamic_cast<Idea*>(*it);
    accum += i->value();
  }
  return accum;
}

bool cprog_game::IdeaContainer::add(Object* o) {
  Idea* i = dynamic_cast<Idea*>(o);
  if(i != 0) {
    return Container::add(o);
  }
  return false;
}
