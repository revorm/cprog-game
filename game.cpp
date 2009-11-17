#include <iostream>

#include "char/troll.h"

int main(int argc, char **argv) {
  Troll t(std::string("nisse"));
  Troll t2(std::string("anders"));
  t.talk_to(&t2);
  return 0;
}
