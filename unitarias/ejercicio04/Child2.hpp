// Copyright 2017 Gerardo Teruel
#ifndef CHILD2_H_
#define CHILD2_H_

#include "Base.hpp"

class Child2 : public Base {
 public:
  int doSomething() override {
    std::cout << "Child 2" << '\n';
    return 1;
  }
};

#endif  // CHILD2_H_
