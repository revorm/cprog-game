#ifndef OUTDOOR_H
#define OUTDOOR_H

#include "environment.h"

class Outdoor : public Environment
{
public:
  Outdoor(const std::string& name, const std::string& desc) :
      Environment(name,desc) {}
};

#endif // OUTDOOR_H
