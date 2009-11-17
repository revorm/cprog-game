#ifndef CHARACTER_H
#define CHARACTER_H

#include "../env/environment.h"

#include <string>
#include <vector>

class Character
{
public:
  const std::string& type() const;
  const std::string& name() const;
  virtual void go(Environment::Direction d); // allow override
  virtual void pick_up(Object* o); // allow override
  virtual void drop(Object* o); // allow override

  virtual void action() = 0;
  virtual void talk_to(Character*) = 0;

protected:
  Character(const std::string& type,
            const std::string& name) : m_type(type), m_name(name) {}
  Environment* m_current_environment;
  std::vector<Object*> m_inventory;
  std::string m_type;
  std::string m_name;

};

#endif // CHARACTER_H
