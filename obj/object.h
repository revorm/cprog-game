#ifndef OBJECT_H
#define OBJECT_H

class Object
{
public:
  virtual int weight() const; // allow override, for containers for example
  virtual int value() const;

protected:
  Object(int weight, int value) : m_weight(weight), m_value(value) {}
  int m_weight;
  int m_value;
};

#endif // OBJECT_H
