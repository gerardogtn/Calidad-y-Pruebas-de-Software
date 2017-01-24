// Copyright 2017 Gerardo Teruel
#ifndef SELECTIONSORTER_H_
#define SELECTIONSORTER_H_

#include <algorithm>
#include <vector>

template <typename T>
class SelectionSorter : public Sorter<T> {
 public:
  void mysort(const std::vector<T>& source, std::vector<T>* target) {
    this->mycopy(source, target);

    for (int i = 0; i < target->size() - 1; i++) {
      int iMin = i;
      for (int j = i; j < target->size(); j++) {
        if (target->at(j) < target->at(iMin)) {
          iMin = j;
        }
      }
      if (iMin != i) {
        std::swap(target->at(iMin), target->at(i));
      }
    }
  }
};

#endif  // SELECTIONSORTER_H_
