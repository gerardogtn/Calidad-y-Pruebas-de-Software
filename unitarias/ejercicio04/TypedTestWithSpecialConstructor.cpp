#include "gmock/gmock.h"
#include "Child1.hpp"
#include "Child2.hpp"
#include "Child3.hpp"

using testing::Eq;
using testing::Test;
using testing::Types;

template <typename T>
Base* factoryMethod() {
  return new T();
}

template<>
Base* factoryMethod<Child3>() {
  return new Child3(10);
}

template <typename T>
class ADerivedBaseWithSpecialConstructor : public Test {
 public:
  Base* derivedBase;

  ADerivedBaseWithSpecialConstructor() : derivedBase(factoryMethod<T>()) {}
  virtual ~ADerivedBaseWithSpecialConstructor() {
    if (derivedBase) {
      delete derivedBase;
    }
    derivedBase = nullptr;
  }
};

typedef Types<Child1, Child2, Child3> DerivedBases;

TYPED_TEST_CASE(ADerivedBaseWithSpecialConstructor, DerivedBases);

TYPED_TEST(ADerivedBaseWithSpecialConstructor, ReturnsOneInDoSomething) {
  ASSERT_THAT(this->derivedBase->doSomething(), Eq(1));
}
