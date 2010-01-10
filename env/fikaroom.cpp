#include "fikaroom.h"

#include "../char/examiner.h"

bool cprog_game::FikaRoom::can_enter(Character *c) {
  if(dynamic_cast<Examiner*>(c)) {
    return true;
  } else {
    return false;
  }
}
