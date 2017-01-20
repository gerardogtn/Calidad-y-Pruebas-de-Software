#include "gmock/gmock.h"
#include "Base.hpp"
#include "Child1.hpp"
#include "Child2.hpp"

using testing::Eq;
using testing::Test;
using testing::Types;

template <typename T>
class ADerivedBase : public Test {
 public:
  T derivedBase;
};

typedef Types<Child1, Child2> DerivedBases;

TYPED_TEST_CASE(ADerivedBase, DerivedBases);

TYPED_TEST(ADerivedBase, ReturnsOneInDoSomething) {
  ASSERT_THAT(this->derivedBase.doSomething(), Eq(1));
}
