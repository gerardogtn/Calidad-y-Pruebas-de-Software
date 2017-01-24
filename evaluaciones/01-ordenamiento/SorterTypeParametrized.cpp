// Copyright 2017 Gerardo Teruel
#include <vector>
#include "gmock/gmock.h"
#include "Sorter.hpp"
#include "BubbleSorter.hpp"
#include "CountSorter.hpp"
#include "InsertionSorter.hpp"
#include "QuickSorter.hpp"
#include "SelectionSorter.hpp"

using testing::Test;
using testing::Eq;

template <typename SorterInstance>
class SorterTypeParametrized : public Test {
 public:
  Sorter<int>* sorter;
  std::vector<int> unsorted;
  std::vector<int> sorted;

  SorterTypeParametrized() : sorted({1, 2, 3, 4, 5, 6}),
      unsorted({6, 3, 1, 2, 4, 5}) {
    sorter = new SorterInstance;
  }

  virtual ~SorterTypeParametrized() {
    delete sorter;
    sorter = nullptr;
  }
};

TYPED_TEST_CASE_P(SorterTypeParametrized);

TYPED_TEST_P(SorterTypeParametrized, SampleSort) {
  std::vector<int> out;

  this->sorter->mysort(this->unsorted, &out);

  ASSERT_THAT(this->sorted, Eq(out));
}

REGISTER_TYPED_TEST_CASE_P(SorterTypeParametrized, SampleSort);

typedef testing::Types<BubbleSorter<int>, CountSorter<int>, InsertionSorter<int>, QuickSorter<int>, SelectionSorter<int>> Sorters;

INSTANTIATE_TYPED_TEST_CASE_P(InstancesTest, SorterTypeParametrized, Sorters);
