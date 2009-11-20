#include <iostream>

#include "memhandler.h"
#include "obj/container.h"
#include "char/character.h"
#include "env/environment.h"

int main(int argc, char **argv) {
  Memhandler<Object>::get().insert(new Container(1,10,"a","b",10));


  Memhandler<Character>::get().free();
  Memhandler<Environment>::get().free();
  Memhandler<Object>::get().free();
  return 0;
}
