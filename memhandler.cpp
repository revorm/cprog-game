#include "memhandler.h"

class Object;
class Environment;
class Character;

template<>
Memhandler<Object>* Memhandler<Object>::s_instance = 0;

template<>
Memhandler<Environment>* Memhandler<Environment>::s_instance = 0;

template<>
Memhandler<Character>* Memhandler<Character>::s_instance = 0;
