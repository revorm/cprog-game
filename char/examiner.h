#ifndef EXAMINER_H
#define EXAMINER_H

#include "character.h"

class Examiner : public Character
{
public:
  Examiner(const std::string& name) : Character(name) {}
};

#endif // EXAMINER_H
