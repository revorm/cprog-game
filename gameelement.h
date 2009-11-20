#ifndef GAMEELEMENT_H
#define GAMEELEMENT_H

#include <string>

class GameElement
{
public:
  const std::string& name() const {
    return m_name;
  }
  virtual ~GameElement() {}
protected:
  GameElement(const std::string& name) : m_name(name) {}

private:
  const std::string m_name;
};

#endif // GAMEELEMENT_H
