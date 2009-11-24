#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "../gameelement.h"

#include <vector>
#include <map>

class Character;
class Object;

class Environment : public GameElement
{
public:
  typedef std::map<std::string,Object*> Inventory_t;

  enum Direction { NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3};
  const std::map<Direction,Environment*> directions() const;
  Environment* neighbor(Direction) const;
  virtual std::string description() const;
  virtual void interact(Character*) {} // default interact is a no-op, but allow override

  // allow override to be able to hook in on a character entering / exiting
  virtual void enter(Character*);
  virtual void leave(Character*);

  // allow override to be able to hook in when an object is picked up
  virtual Object* get_item(const std::string& name);
  virtual void put_item(const std::string& name, Object* o);

  std::pair<Inventory_t::const_iterator,Inventory_t::const_iterator>
      objects() const;


protected:
  Environment(const std::string& name, const std::string& desc) : GameElement(name), m_description(desc) {}
  void add_neighbor(Direction d, Environment* e);
  std::string m_description;
  std::map<std::string,Object*> m_objects;
  std::map<Direction,Environment*> m_neighbors;
  std::vector<Character*> m_characters;
};

#endif // ENVIRONMENT_H
