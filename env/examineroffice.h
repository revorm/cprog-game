#ifndef EXAMINEROFFICE_H
#define EXAMINEROFFICE_H

#include "environment.h"

namespace cprog_game {
class ExaminerOffice : public Environment
{
public:
  ExaminerOffice(const std::string& name, const std::string& desc) : Environment(name,desc) {}

  bool can_enter(Character *);
};
}

#endif // EXAMINEROFFICE_H
