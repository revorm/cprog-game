#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "../gameelement.h"

#include <vector>
#include <map>

namespace cprog_game{
  class Character;
  class Object;
  
  class Environment : public GameElement
  {
  public:
    enum Direction { NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3};
  
    typedef std::map<std::string,Object*> Inventory_t;
    typedef std::map<Direction,Environment*> Direction_map;
    const std::map<Direction,Environment*> directions() const;
    Environment* neighbor(Direction) const;
    virtual std::string description() const;
  
    // allow override to be able to hook in on a character entering / exiting
    virtual void enter(Character*);
    virtual void leave(Character*);
  
    // allow override to be able to hook in when an object is picked up
    virtual Object* get_item(const std::string& name);
    virtual void put_item(Object* o);
  
    const Inventory_t& objects() const;
  
    void interact(Character *) {}

    virtual bool can_enter(Character *);

    const std::vector<Character*>& characters() const;
  
    friend class GameEngine;
  
  protected:
    Environment(const std::string& name, const std::string& desc) : GameElement(name), m_description(desc) {}
    void add_neighbor(Direction d, Environment* e);
    std::string m_description;
    std::map<std::string,Object*> m_objects;
    std::map<Direction,Environment*> m_neighbors;
    std::vector<Character*> m_characters;
  };
}

#endif // ENVIRONMENT_H
