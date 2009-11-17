#ifndef CONTAINER_H
#define CONTAINER_H

#include "object.h"
#include <vector>

class Container : public Object
{
public:
  Container(int weight, int value, int max_weight) : Object(weight,value), m_max_weight(max_weight) {}
  int weight() const;
  int value() const;

  bool add(Object* o);
  bool remove(Object* o);

  int max_weight() const;

private:
  int m_max_weight;
  std::vector<Object*> m_contents;
};

#endif // CONTAINER_H
