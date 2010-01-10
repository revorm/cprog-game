#include "gameengine.h"

#include "../env/environment.h"
#include "../env/computerroom.h"
#include "../env/examineroffice.h"
#include "../env/fikaroom.h"
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
#include <cstdlib>
#include <iostream>
#include <fstream>

void cprog_game::GameEngine::init() {
  srand(unsigned(time(NULL)));
  // Create environments and add to the game
  Environment* computer_room = new ComputerRoom("room", "Computer room");
  add_to_game(computer_room);
  Environment* e_house = new Environment("e_house", "A house at kth.");
  add_to_game(e_house);
  Environment* esc = new TheEscape("the_escape", "A room full of computer science students, you recognize most of them.");
  add_to_game(esc);
  Environment* fika_room = new FikaRoom("fika_room", "A room where the examinator gets his coffe.");
  add_to_game(fika_room);
  Environment* office = new ExaminerOffice("office", "The examinators office.");
  add_to_game(office);
  Environment* out = new Outdoor("osquars_backe", "You feel a strong wind blowing from the south, if you drop something here "
                                 "it's likely to blow away and disappear forever.");
  add_to_game(out);
  Environment* sleven = new Sleven("7-11", "Your favourite place to buy a coffee.");
  add_to_game(sleven);

  // create neighborhood
  computer_room->add_neighbor(Environment::SOUTH, e_house);
  e_house->add_neighbor(Environment::WEST, out);
  e_house->add_neighbor(Environment::NORTH, computer_room);
  e_house->add_neighbor(Environment::EAST, office);
  esc->add_neighbor(Environment::SOUTH, out);
  fika_room->add_neighbor(Environment::SOUTH, office);
  office->add_neighbor(Environment::WEST, out);
  office->add_neighbor(Environment::NORTH, fika_room);
  out->add_neighbor(Environment::NORTH, esc);
  out->add_neighbor(Environment::EAST, e_house);
  out->add_neighbor(Environment::SOUTH, sleven);
  sleven->add_neighbor(Environment::NORTH, out);

  // create objects and add to game
  // container
  Object* o = new IdeaContainer();
  esc->put_item(o);
  add_to_game(o);
  // ideas
  Idea* good_idea_1 = new Idea("idea1", "KISS - keep it simple stupid", 10);
  add_to_game(good_idea_1);
  Idea* good_idea_2 = new Idea("idea2", "I can teach you everything about inheritance that you will ever need.", 40);
  add_to_game(good_idea_2);
  Idea* good_idea_3 = new Idea("idea3", "Dude, templates rock!", 30);
  add_to_game(good_idea_3);
  Idea* bad_idea_1 = new Idea("idea4",  "Object oriented programming is overrated.", -30);
  add_to_game(bad_idea_1);
  Idea* bad_idea_2 = new Idea("idea5",  "void* is your friend.", -20);
  add_to_game(bad_idea_2);
  
  // create characters and add to game
  Friend* david = new Friend("David Björklund", computer_room, good_idea_2, 2);
  add_to_game(david);
  Friend* pelle = new Friend("Per Almquist", computer_room, good_idea_1, 3);
  add_to_game(pelle);
  Friend* erik = new Friend("Erik Hammar", esc, good_idea_3, 1);
  add_to_game(erik);
  Friend* svamp = new Friend("Johan Björk", sleven, bad_idea_1, 4);
  add_to_game(svamp);
  Friend* ture = new Friend("Ture Teknolog", e_house, bad_idea_2, 5);
  add_to_game(ture);

  Examiner* alex = new Examiner("Alexander Baltazis", office);
  add_to_game(alex);
  
  Oracle* oracle = new Oracle("Oraklet", sleven);
  add_to_game(oracle);

  if(m_interactive) {
    Player* p = new Player("player",out);
    add_to_game(p);
    {
      std::ifstream help_file("readme.txt",std::ios_base::in);
      std::string line;
      while(std::getline(help_file,line)) {
        p->inform(line);
      }
    }
    p->inform("");
    p->controller()->commands()->look(std::vector<std::string>());
  }
}
