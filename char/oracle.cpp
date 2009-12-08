#include "oracle.h"

#include <cstdlib>

static const char *const messages[] = {
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

void Oracle::interact(Character *c) {
  unsigned int r = rand() % sizeof(messages);
  say_to(c,messages[r]);
}

void Oracle::action() {
  static int counter = 0;
  if((counter++ % 10) == 0) {
    const Environment::Direction_map m = environment()->directions();
    unsigned int r = rand() % m.size();
    Environment::Direction_map::const_iterator it = m.begin();
    while(r--) { ++it; }
    go(it->first);
  }
}
