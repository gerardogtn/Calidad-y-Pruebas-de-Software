// Copyright 2017 Gerardo Teruel
#include "gmock/gmock.h"
#include "Almacen.hpp"

using testing::Eq;
using testing::Test;

class AnEmptyAlmacen : public Test {
 public:
  Almacen<int> almacen;
};

TEST_F(AnEmptyAlmacen, IsEmpty) {
  ASSERT_THAT(almacen.empty(), Eq(true));
}

TEST_F(AnEmptyAlmacen, HasSizeZero) {
  ASSERT_THAT(almacen.size(), Eq(0));
}

class AOneSizedAlmacen : public Test {
 public:
  const int ELEMENT = 5;
  const int OTHER = 3;
  Almacen<int> almacen;

  AOneSizedAlmacen() {
    almacen.addFirst(ELEMENT);
  }
};

TEST_F(AOneSizedAlmacen, AddFirstIsHead) {
  almacen.addFirst(OTHER);

  ASSERT_THAT(almacen.head(), Eq(OTHER));
}

TEST_F(AOneSizedAlmacen, AddLastIsTail) {
  almacen.addLast(OTHER);

  ASSERT_THAT(almacen.tail(), Eq(OTHER));
}

TEST_F(AOneSizedAlmacen, IsEmptyAfterRemoving) {
  almacen.remove(0);

  ASSERT_THAT(almacen.empty(), Eq(true));
}

TEST_F(AOneSizedAlmacen, SizeIsZeroAfterRemoving) {
  almacen.remove(0);

  ASSERT_THAT(almacen.size(), Eq(0));
}
