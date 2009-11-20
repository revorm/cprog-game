#ifndef IDEACONTAINER_H
#define IDEACONTAINER_H

#include "container.h"

class IdeaContainer : public Container
{
public:
  IdeaContainer(const std::string& name) : Container(name,0,0,std::string("A bag that you can put your ideas in"),6) {}

  int value() const;

  bool add(Object* o);

};

#endif // IDEACONTAINER_H
