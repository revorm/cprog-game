#ifndef EXAMINER_H
#define EXAMINER_H

#include "character.h"

class Examiner : public Character
{
public:
  Examiner(const std::string& name) : Character(name) {}

  void action();
  void interact(Character * c);

  void inform(const std::string &s);
private:
  bool m_examining;
  const static int EXAMINER_MOOD;
};

#endif // EXAMINER_H
