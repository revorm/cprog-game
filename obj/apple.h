#ifndef APPLE_H
#define APPLE_H

#include "object.h"

namespace cprog_game {
  class Apple : public Object
  {
  public:
    Apple(const std::string& name) : Object(name,0,0,"an apple suitable for a schoolteacher") {}

    void interact(Character *) {}
  };
}

#endif // APPLE_H
