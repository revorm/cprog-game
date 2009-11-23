#ifndef SLEVEN_H
#define SLEVEN_H

#include "environment.h"

class Sleven : public Environment
{
public:
  Sleven(const std::string& name, const std::string& desc) : Environment(name,desc) {}

  void interact(Character * c);
};

#endif // SLEVEN_H
