#ifndef GAMEELEMENT_H
#define GAMEELEMENT_H

#include "engine/gameengine.h"

#include <string>

namespace cprog_game
{
  class Character;
  
  class GameElement
  {
  public:
    /*!
      Interact has a sort of reverse semantic.
      If a person wants to interact with another
      game entity it will call that->interact(this)
     */
    virtual void interact(Character*) = 0;
  
    const std::string& name() const {
      return m_name;
    }
    virtual ~GameElement() {}
  protected:
    GameElement(const std::string& name) : m_name(name) {}
  
  private:
    GameElement(const GameElement&);
    const std::string m_name;
  };
}

#endif // GAMEELEMENT_H
