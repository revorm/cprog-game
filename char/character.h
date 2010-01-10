#ifndef CHARACTER_H
#define CHARACTER_H

#include "../gameelement.h"
#include "../env/environment.h"

#include <string>
#include <map>

namespace cprog_game
{
  class Character : public GameElement
  {
  public:
    const static int START_ENERGY;

    typedef std::map<std::string,Object*> Inventory_t;

    Environment* environment() const;

    /**
     * @return true if character managed to walk in direction, false otherwise
     */
    virtual bool go(Environment::Direction d); // allow override
    /**
     * @return true if object got picked up, false otherwise
     */
    virtual bool pick_up(const std::string& name); // allow override
    /**
     * @return true if object was dropped, false otherwise
     */
    virtual bool drop(const std::string& name); // allow override

    virtual void action() = 0;

    virtual void inform(const std::string& s);

    const Inventory_t& inventory() const;
    int energy() const;
    void add_energy(int add);

    void say_to(Character* c, const std::string& message) const;

  protected:
    Character(const std::string& name, Environment* start_env) : GameElement(name), m_current_environment(start_env), m_energy(START_ENERGY) {}
    Environment* m_current_environment;
    Inventory_t m_inventory;
    int m_energy;
  };
}
#endif // CHARACTER_H
