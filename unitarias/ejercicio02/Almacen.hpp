// Copyright 2017 Gerardo Teruel

#ifndef ALMACEN_H_
#define ALMACEN_H_

#include <list>

template <typename T>
class Almacen {
 private:
  std::list<T> ingredients;

 public:
  Almacen() {}
  virtual ~Almacen() {}

  T head() {
    return ingredients.front();
  }

  T tail() {
    return ingredients.back();
  }

  void addLast(T i) {
    ingredients.push_back(i);
  }

  void addFirst(T i) {
    ingredients.push_front(i);
  }

  /** Remove the element at given position */
  void remove(int pos) {
    auto it = ingredients.begin();
    std::advance(it, pos);
    ingredients.erase(it);
  }

  bool empty() {
    return ingredients.empty();
  }

  int size() {
    return ingredients.size();
  }
};

#endif  // ALMACEN_H_
