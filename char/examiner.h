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
  private:
    enum mood{
      GOOD = 5, BAD = 7
    };
    mood m_examiner_mood;
    int m_move_timer;
    int m_move;
    const static int FIKA_TIMEOUT;
  };
  }
#endif // EXAMINER_H
