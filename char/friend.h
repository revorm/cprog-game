#ifndef FRIEND_H
#define FRIEND_H

#include "character.h"

class Idea;

class Friend : public Character
{
public:
  Friend(const std::string& name, Idea* i) : Character(name), m_idea(i) {}

  void interact(Character *);

  void action();

private:
  Idea* m_idea;
};

#endif // FRIEND_H
