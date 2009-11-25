#ifndef OBJECT_H
#define OBJECT_H

#include "../gameelement.h"

class Character;

class Object : public GameElement
{
public:
  virtual int weight() const; // allow override, for containers for example
  virtual int value() const;

  virtual std::string description() const;

protected:
  Object(const std::string& name, int weight, int value, const std::string& desc)
      : GameElement(name), m_weight(weight), m_value(value), m_description(desc) {}
  int m_weight;
  int m_value;
  std::string m_name;
  std::string m_description;
};

#endif // OBJECT_H
