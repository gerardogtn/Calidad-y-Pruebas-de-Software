// Copyright 2017 Gerardo Teruel
#ifndef COUNTSORTER_H_
#define COUNTSORTER_H_

#include <algorithm>
#include <map>
#include <vector>

template <typename T>
class CountSorter : public Sorter<T> {
 public:
  void mysort(const std::vector<T>& source, std::vector<T>* target) {
    std::map<T, int> map;
    for (T t : source) {
      map[t]++;
    }

    for (auto value : map) {
      for (int i = 0; i < value.second; i++) {
        target->push_back(T(value.first));
      }
    }
  }
};

#endif  // COUNTSORTER_H_
