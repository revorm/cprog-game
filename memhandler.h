#ifndef MEMHANDLER_H
#define MEMHANDLER_H

#include <vector>

template<typename T>
class Memhandler
{
public:
  static Memhandler& get();
  static void free();
  void insert(T* t);
private:
  Memhandler();
  ~Memhandler();
  std::vector<T*> m_v;
  static Memhandler* s_instance;
};

template<typename T>
Memhandler<T>& Memhandler<T>::get() {
  if(s_instance == 0) {
    s_instance = new Memhandler();
  }
  return *s_instance;
}

template<typename T>
void Memhandler<T>::free() {
  if(s_instance != 0)
    delete s_instance;
  s_instance = 0;
}

template<typename T>
Memhandler<T>::Memhandler() {}

template<typename T>
Memhandler<T>::~Memhandler() {
  for(typename std::vector<T*>::const_iterator it = m_v.begin();
  it != m_v.end(); ++it) {
    delete (*it);
  }
  m_v.clear();
}

template<typename T>
void Memhandler<T>::insert(T *t) {
  m_v.push_back(t);
}


#endif // MEMHANDLER_H
