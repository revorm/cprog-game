#ifndef IDEACONTAINER_H
#define IDEACONTAINER_H

#include "container.h"

namespace cprog_game
{
  class IdeaContainer : public Container
  {
  public:
    const static std::string ITEM_NAME;
  
    IdeaContainer() : Container(ITEM_NAME,0,0,std::string("A bag that you can put your ideas in"),6) {}
  
    int value() const;
  
    bool add(Object* o);
  
  };
}

#endif // IDEACONTAINER_H
