#ifndef COFFEE_H
#define COFFEE_H

#include "object.h"

class Coffee : public Object
{
public:
  const static int WEIGHT;
  const static int VALUE;

  Coffee(const std::string& name, const std::string& desc) :
      Object(name,WEIGHT,VALUE,desc) {}

  void interact(Character* c);
};

#endif // COFFEE_H
