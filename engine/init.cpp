#include "gameengine.h"

#include "../env/environment.h"
#include "../env/computerroom.h"
#include "../env/outdoor.h"
#include "../env/sleven.h"
#include "../env/theescape.h"

#include "../char/character.h"
#include "../char/examiner.h"
#include "../char/friend.h"
#include "../char/oracle.h"
#include "../char/player.h"

#include "../obj/object.h"
#include "../obj/coffee.h"
#include "../obj/gamesourcetarball.h"
#include "../obj/idea.h"
#include "../obj/ideacontainer.h"

#include <cassert>

void GameEngine::init() {
  srand(unsigned(time(NULL)));
  Environment* e = new ComputerRoom(std::string("room"),std::string("Computer room"));
  Environment* out = new Outdoor("osquars_backe","You feel a strong wind blowing from the south, if you drop something here "
                                 "it's likely to blow away and disappear forever.");
  Environment* esc = new TheEscape("the_escape","A room full of computer science students, you recognize most of them.");
  Object* o = new IdeaContainer();
  esc->put_item(o);
  esc->add_neighbor(Environment::WEST,out);
  out->add_neighbor(Environment::EAST,esc);
  out->add_neighbor(Environment::SOUTH,e);
  e->add_neighbor(Environment::NORTH,out);
  Player* p = new Player(std::string("player"),out);
  add_to_game(e->name(),e);
  add_to_game(p->name(),p);
  add_to_game(out->name(),out);
  add_to_game(esc->name(),esc);
  add_to_game(o->name(),o);

  assert(p->inventory().empty());
  assert(p->environment() == out);
  p->go(Environment::EAST);
  assert(p->environment() == esc);
  p->pick_up(IdeaContainer::ITEM_NAME);
  assert(p->inventory().size() == 1);
  p->go(Environment::WEST);
  p->go(Environment::SOUTH);
  e->interact(p);
  p->inform(esc->description());
  game_finished();
}
