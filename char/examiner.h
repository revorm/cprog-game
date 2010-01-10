#ifndef EXAMINER_H
#define EXAMINER_H

#include "character.h"

namespace cprog_game
{  
  class Examiner : public Character
  {
  public:
    Examiner(const std::string& name, Environment* start_env);
  
    void action();
    void interact(Character * c);
  
    void inform(const std::string &s);
  private:
    enum mood{
      GOOD = 5, BAD = 7
    };
    bool m_examining;
    bool m_should_exit;
    mood m_examiner_mood;
  };
  }
#endif // EXAMINER_H
