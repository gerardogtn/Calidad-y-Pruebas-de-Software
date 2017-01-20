// Copyright 2017 Gerardo Teruel
#ifndef CHILD3_H_
#define CHILD3_H_

#include <iostream>
#include "Base.hpp"

class Child3 : public Base {
 private:
  int someValue;

 public:
  explicit Child3(int value) : someValue(value) {
  }

  int doSomething() override {
    std::cout << "Child3" << '\n';
    return 1;
  }
};

#endif  // CHILD3_H_
