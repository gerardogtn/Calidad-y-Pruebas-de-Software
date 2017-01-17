// Copyright 2017 Gerardo Teruel
#include "gmock/gmock.h"
#include "functions.h"

using testing::Eq;
using testing::Range;
using testing::TestWithParam;

class AnEvenPositiveInteger : public TestWithParam<int> {
};

TEST_P(AnEvenPositiveInteger, EvenNumbersAreEven) {
  ASSERT_THAT(isEven(GetParam()), Eq(true));
}

TEST_P(AnEvenPositiveInteger, EvenNumbersAreNotOdd) {
  ASSERT_THAT(isOdd(GetParam()), Eq(false));
}

class AnOddPositiveInteger : public TestWithParam<int> {
};

TEST_P(AnOddPositiveInteger, OddNumbersAreOdd) {
  ASSERT_THAT(isOdd(GetParam()), Eq(true));
}

TEST_P(AnOddPositiveInteger, OddNumbersAreNotEven) {
  ASSERT_THAT(isEven(GetParam()), Eq(false));
}

INSTANTIATE_TEST_CASE_P(EvenNumbers, AnEvenPositiveInteger, Range(0, 100, 2));
INSTANTIATE_TEST_CASE_P(EvenNumbers, AnOddPositiveInteger, Range(1, 100, 2));
