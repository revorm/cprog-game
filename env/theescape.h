#ifndef THEESCAPE_H
#define THEESCAPE_H

#include "environment.h"

namespace cprog_game
{
  class TheEscape : public Environment
  {
  public:
    TheEscape(const std::string& name, const std::string& desc) : Environment(name,desc) {}
  };
}

#endif // THEESCAPE_H
