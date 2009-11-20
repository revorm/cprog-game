#ifndef CONTAINER_H
#define CONTAINER_H

#include "object.h"
#include <vector>

class Container : public Object
{
public:
  Container(int weight, int value, const std::string& name, const std::string& desc, int max_weight) :
      Object(weight,value,name,desc), m_max_weight(max_weight) {}
  int weight() const;
  int value() const;

  virtual bool add(Object* o);
  virtual bool remove(Object* o);

  void interact(Character* c);

  int max_weight() const;

protected:
  int m_max_weight;
  std::vector<Object*> m_contents;
};

#endif // CONTAINER_H
