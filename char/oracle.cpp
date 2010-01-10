#include "oracle.h"

#include <string>
#include <cstdlib>

static const std::string messages[] = {
"As I see it, yes",
"It is certain",
"It is decidedly so",
"Most likely",
"Outlook good",
"Signs point to yes",
"Without a doubt",
"Yes",
"Yes - definitely",
"You may rely on it",
"Reply hazy, try again",
"Ask again later",
"Better not tell you now",
"Cannot predict now",
"Concentrate and ask again",
"Don't count on it",
"My reply is no",
"My sources say no",
"Outlook not so good",
"Very doubtful" };

void cprog_game::Oracle::interact(Character *c) {
  unsigned int r = rand() % sizeof(messages)/sizeof(std::string*);
  say_to(c,messages[r]);
}

void cprog_game::Oracle::action() {
  static int counter = 0;
  if((counter++ % 2) == 0) {
    const Environment::Direction_map m = environment()->directions();
    unsigned int r = rand() % m.size();
    Environment::Direction_map::const_iterator it = m.begin();
    while(r--) { ++it; }
    go(it->first);
    if(environment()->characters().size() > 1){
      interact(environment()->characters()[0]);
    }
  }
}
