#ifndef CHARACTER_H
#define CHARACTER_H

#include "../gameelement.h"
#include "../env/environment.h"

#include <string>
#include <map>

class Character : public GameElement
{
public:
  const static int START_ENERGY;

  typedef std::map<std::string,Object*> Inventory_t;

  Environment* environment() const;

  virtual void go(Environment::Direction d); // allow override
  virtual void pick_up(const std::string& name); // allow override
  virtual void drop(const std::string& name); // allow override

  virtual void action() = 0;
  virtual void talk_to(Character*) = 0;


  std::pair<Inventory_t::const_iterator,Inventory_t::const_iterator>
      inventory() const;
  int energy() const;
  void add_energy(int add);

protected:
  Character(const std::string& name) : GameElement(name), m_energy(START_ENERGY) {}
  Environment* m_current_environment;
  std::map<std::string,Object*> m_inventory;
  int m_energy;
};

#endif // CHARACTER_H
