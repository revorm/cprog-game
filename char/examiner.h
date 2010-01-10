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
    void set_good_mood();
    void inform(const std::string &s);
  private:
    enum mood{
      GOOD = 5, BAD = 7
    };
    bool m_examining;
    bool m_should_exit;
    mood m_examiner_mood;
    int m_move_timer;
    const static int FIKA_TIMEOUT;
  };
  }
#endif // EXAMINER_H
