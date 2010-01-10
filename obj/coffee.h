#ifndef COFFEE_H
#define COFFEE_H

#include "object.h"

namespace cprog_game
{
  class Coffee : public Object
  {
  public:
    const static int WEIGHT;
    const static int VALUE;
  
    const static std::string DESCRIPTION;
  
    Coffee(const std::string& name) :
        Object(name,WEIGHT,VALUE,DESCRIPTION) {}
  
    void interact(Character* c);
  };
}

#endif // COFFEE_H
