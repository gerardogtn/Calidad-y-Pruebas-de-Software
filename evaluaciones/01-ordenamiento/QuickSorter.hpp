// Copyright 2017 Gerardo Teruel
#ifndef QUICKSORTER_H_
#define QUICKSORTER_H_

#include <algorithm>
#include <vector>

template <typename T>
class QuickSorter : public Sorter<T> {
 public:
  void mysort(const std::vector<T>& source, std::vector<T>* target) {
    this->mycopy(source, target);
    quicksort(target, 0, target->size() - 1);
  }

 private:
  void quicksort(std::vector<T>* target, size_t lo, size_t hi) {
    if (lo < hi) {
      size_t partitionIndex = partition(target, lo, hi);
      quicksort(target, lo, partitionIndex - 1);
      quicksort(target, partitionIndex + 1, hi);
    }
  }

  size_t partition(std::vector<T>* target, size_t lo, size_t hi) {
    T pivot = target->at(lo);
    size_t leftMark = lo + 1;
    size_t rightMark = hi;

    bool sorted = false;
    while (!sorted) {
      while (leftMark <= rightMark && target->at(leftMark) <= pivot) {
        leftMark++;
      }
      while (target->at(rightMark) >= pivot && rightMark >= leftMark) {
        rightMark--;
      }

      if (rightMark < leftMark) {
        sorted = true;
      } else {
        std::swap(target->at(leftMark), target->at(rightMark));
      }
    }

    std::swap(target->at(lo), target->at(rightMark));
    return rightMark;
  }
};

#endif  // QUICKSORTER_H_
