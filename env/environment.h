#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <string>
#include <vector>
#include <map>

class Character;
class Object;

class Environment
{
public:
  enum Direction { NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3};
  virtual const std::vector<Direction>& directions() const = 0;
  virtual Environment* neighbor(Direction) const = 0;
  virtual const std::string& description() const = 0;
  virtual void enter(Character*); // allow override
  virtual void leave(Character*); // allow override
  virtual bool pick_up(Object* o); // allow override
  virtual void drop(Object* o); // allow override

protected:
  Environment() {}
  void add_neighbor(Direction d, Environment* e);
  void add_object(Object* o);

  std::vector<Object*> m_objects;
  std::map<Direction,Environment*> m_neighbors;
  std::vector<Character*> m_characters;
};

#endif // ENVIRONMENT_H
