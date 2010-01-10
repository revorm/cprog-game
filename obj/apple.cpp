#include "apple.h"

#include "../char/examiner.h"

void cprog_game::Apple::interact(Character *c) {
  Examiner* e = 0;
  if( (e  = dynamic_cast<Examiner*>(c)) ) {
    e->set_good_mood();
  }
}
