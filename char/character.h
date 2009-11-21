#ifndef CHARACTER_H
#define CHARACTER_H

#include "../gameelement.h"
#include "../env/environment.h"

#include <string>
#include <vector>

class Character : public GameElement
{
public:
  const static int START_ENERGY;

  const std::string& type() const;
  Environment* environment() const;

  virtual void go(Environment::Direction d); // allow override
  virtual void pick_up(Object* o); // allow override
  virtual void drop(Object* o); // allow override

  virtual void action() = 0;
  virtual void talk_to(Character*) = 0;

  const std::vector<Object*>& inventory() const;
  int energy() const;
  void add_energy(int add);

protected:
  Character(const std::string& name,
            const std::string& type
            ) : GameElement(name) ,m_type(type), m_energy(START_ENERGY) {}
  std::string m_type;
  Environment* m_current_environment;
  std::vector<Object*> m_inventory;
  int m_energy;
};

#endif // CHARACTER_H
