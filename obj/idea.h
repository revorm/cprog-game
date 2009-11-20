#ifndef IDEA_H
#define IDEA_H

#include "object.h"

class Idea : public Object
{
public:
  Idea(const std::string& name, const std::string& desc, int value, bool good_idea) :
      Object(name,1,value,desc), m_good_idea(good_idea) {}

  bool is_good() const;
private:
  bool m_good_idea;
};

#endif // IDEA_H
