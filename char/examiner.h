#ifndef EXAMINER_H
#define EXAMINER_H

#include "character.h"

class Examiner : public Character
{
public:
  Examiner(const std::string& name) : Character(name) {}

  void action();
  void talk_to(Character * c);

};

#endif // EXAMINER_H
