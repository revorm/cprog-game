#ifndef CONTAINER_H
#define CONTAINER_H

#include "object.h"
#include <vector>

namespace cprog_game
{
  class Container : public Object
  {
  public:
    Container(const std::string& name, int weight, int value, const std::string& desc, int max_weight) :
        Object(name,weight,value,desc), m_max_weight(max_weight) {}
    int weight() const;
    int value() const;
  
    virtual bool add(Object* o);
    virtual bool remove(Object* o);
  
    void interact(Character* c);
  
    int max_weight() const;

    std::string description() const;
  
  protected:
    int m_max_weight;
    std::vector<Object*> m_contents;
  };
}
#endif // CONTAINER_H
