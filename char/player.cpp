#include "player.h"
#include "../playercontroller.h"
#include "../obj/object.h"
#include "../obj/idea.h"
#include "../obj/ideacontainer.h"

#include <iostream>

void cprog_game::Player::inform(const std::string &s) {
  m_controller->out() << s << std::endl;
}

void cprog_game::Player::action() {
  m_controller->get_command();
}

bool cprog_game::Player::take(const std::string &name) {
  Object* o = m_current_environment->get_item(name);
  if(o) {
    Idea* i;
    if((i = dynamic_cast<Idea*>(o))) {
      Inventory_t::iterator it;
      if( (it = m_inventory.find("ideabag")) != m_inventory.end() ) {
        IdeaContainer* c = dynamic_cast<IdeaContainer*>(it->second);
        c->add(i);
      } else {
        inform("You need somewhere to put this idea.. your brain is full of yoghurt.");
        return false;
      }
    } else {
      m_inventory.insert(std::make_pair(name,o));
    }
  }
  return o;
}

cprog_game::PlayerController* cprog_game::Player::controller() {
  return m_controller;
}
