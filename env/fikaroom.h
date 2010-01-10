#ifndef FIKAROOM_H
#define FIKAROOM_H

#include "environment.h"

namespace cprog_game
{
  class FikaRoom : public Environment
  {
  public:
    FikaRoom(const std::string& name, const std::string& desc) : Environment(name,desc) {}

    bool can_enter(Character * c);
  };
}
#endif // FIKAROOM_H
