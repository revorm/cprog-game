#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Character;

class Object
{
public:
  virtual int weight() const; // allow override, for containers for example
  virtual int value() const;
  virtual void interact(Character*) = 0;

protected:
  Object(int weight, int value, const std::string& name, const std::string& desc)
      : m_weight(weight), m_value(value), m_name(name), m_description(desc) {}
  int m_weight;
  int m_value;
  std::string m_name;
  std::string m_description;
};

#endif // OBJECT_H
