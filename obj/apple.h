#ifndef APPLE_H
#define APPLE_H

#include "object.h"

namespace cprog_game {
  class Apple : public Object
  {
  public:
    Apple(const std::string& name) : Object(name,1,1,"an apple suitable for a schoolteacher") {}
  };
}

#endif // APPLE_H
