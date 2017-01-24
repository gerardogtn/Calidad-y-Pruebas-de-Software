// Copyright 2017 Gerardo Teruel
#ifndef BUBBLESORTER_H_
#define BUBBLESORTER_H_

#include <algorithm>
#include <vector>

template <typename T>
class BubbleSorter : public Sorter<T> {
 public:
  void mysort(const std::vector<T>& source, std::vector<T>* target) {
    this->mycopy(source, target);

    bool swapped = true;
    while (swapped) {
      swapped = false;
      for (int i = 1; i < target->size(); i++) {
        if (target->at(i - 1) > target->at(i)) {
          std::swap(target->at(i - 1), target->at(i));
          swapped = true;
        }
      }
    }
  }
};

#endif  // BUBBLESORTER_H_
