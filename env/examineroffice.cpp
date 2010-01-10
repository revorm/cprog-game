#include "examineroffice.h"

#include "../char/character.h"

bool cprog_game::ExaminerOffice::can_enter(Character *c) {
  if(c->name() == "player" || c->name() == "examiner") {
    return true;
  }
  return false;
}
