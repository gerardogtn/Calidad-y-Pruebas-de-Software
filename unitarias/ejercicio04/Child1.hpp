// Copyright 2017 Gerardo Teruel
#ifndef CHILD1_H_
#define CHILD1_H_

#include <iostream>
#include "Base.hpp"

class Child1 : public Base {
 public:
  int doSomething() override {
    std::cout << "Child 1" << '\n';
    return 1;
  }
};

#endif  // CHILD1_H_
