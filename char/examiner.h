#ifndef EXAMINER_H
#define EXAMINER_H

#include "character.h"

class Examiner : public Character
{
public:
  Examiner(const std::string& name) : Character(name), m_examining(false), m_should_exit(false) {}

  void action();
  void interact(Character * c);

  void inform(const std::string &s);
private:
  bool m_examining;
  bool m_should_exit;
  const static int EXAMINER_MOOD;
};

#endif // EXAMINER_H
