#ifndef CHARACTER_H
#define CHARACTER_H

#include "../gameelement.h"
#include "../env/environment.h"

#include <string>
#include <vector>

class Character : public GameElement
{
public:
  const std::string& type() const;
  Environment* environment() const;

  virtual void go(Environment::Direction d); // allow override
  virtual void pick_up(Object* o); // allow override
  virtual void drop(Object* o); // allow override

  virtual void action() = 0;
  virtual void talk_to(Character*) = 0;

protected:
  Character(const std::string& name,
            const std::string& type
            ) : GameElement(name) ,m_type(type) {}
  std::string m_type;
  Environment* m_current_environment;
  std::vector<Object*> m_inventory;

};

#endif // CHARACTER_H
