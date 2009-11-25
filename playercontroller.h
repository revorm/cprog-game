#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <ostream>

class PlayerController
{
public:
  PlayerController() {}

  std::ostream& out();

  void get_command();
};

#endif // PLAYERCONTROLLER_H
