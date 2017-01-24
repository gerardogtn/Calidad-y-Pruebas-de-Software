// Copyright 2017 Gerardo Teruel
#ifndef INSERTIONSORTER_H_
#define INSERTIONSORTER_H_

#include <algorithm>
#include <vector>

template <typename T>
class InsertionSorter : public Sorter<T> {
 public:
  void mysort(const std::vector<T>& source, std::vector<T>* target) {
    this->mycopy(source, target);

    for (size_t i = 1; i < target->size(); i++) {
      T value = target->at(i);
      size_t j = i;
      while (j > 0 && target->at(j - 1) > value) {
        target->at(j) = target->at(j - 1);
        j--;
      }
      target->at(j) = value;
    }
  }
};

#endif  // INSERTIONSORTER_H_
