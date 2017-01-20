#include "gmock/gmock.h"
#include "Child1.hpp"
#include "Child2.hpp"
#include "Child3.hpp"

using testing::Eq;
using testing::TestWithParam;
using testing::Values;

typedef Base* factoryMethod();

Base* childOne() {
  return new Child1();
}

Base* childTwo() {
  return new Child2();
}

template <int param>
Base* childWithParam() {
  return new Child3(param);
}

class AFunctionBaseParam : public TestWithParam<factoryMethod*> {
};

TEST_P(AFunctionBaseParam, ReturnsOneInDoSomething) {
  Base* base = (*GetParam())();
  ASSERT_THAT(base->doSomething(), Eq(1));
  delete base;
}

INSTANTIATE_TEST_CASE_P(ValueParemtrizedTest, AFunctionBaseParam, Values(&childOne, &childTwo, &childWithParam<10>));
