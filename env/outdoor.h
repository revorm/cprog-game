#ifndef OUTDOOR_H
#define OUTDOOR_H

#include "environment.h"

namespace cprog_game
{
  class Outdoor : public Environment
  {
  public:
    Outdoor(const std::string& name, const std::string& desc) :
        Environment(name,desc) {}
  
    void put_item(Object *o);
  };
}

#endif // OUTDOOR_H
