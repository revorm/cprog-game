#include <sstream>

#include "idea.h"
#include "../char/character.h"

void cprog_game::Idea::interact(Character* c){
  std::stringstream name;
  name << "My value is " << m_value;
  c->inform(name.str());
}
