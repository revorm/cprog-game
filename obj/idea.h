#ifndef IDEA_H
#define IDEA_H

#include "object.h"

class Idea : public Object
{
public:
  Idea(std::string& name, std::string& desc, int value, bool good_idea) :
      Object(1,value,name,desc), m_good_idea(good_idea) {}

  bool is_good() const;
private:
  bool m_good_idea;
};

#endif // IDEA_H
