#include "ideacontainer.h"

#include "idea.h"

const std::string IdeaContainer::ITEM_NAME("ideabag");

int IdeaContainer::value() const {
  int accum = 0;
  for(std::vector<Object*>::const_iterator it = m_contents.begin(); it != m_contents.end(); ++it) {
    Idea* i = dynamic_cast<Idea*>(*it);
    accum += (i->is_good() ? i->value() : -i->value());
  }
  return accum;
}

bool IdeaContainer::add(Object* o) {
  Idea* i = dynamic_cast<Idea*>(o);
  if(i != 0) {
    return Container::add(o);
  }
  return false;
}
