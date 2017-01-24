// Copyright 2017 Gerardo Teruel
#ifndef SORTER_H_
#define SORTER_H_

#include <vector>

template <typename T>
class Sorter {
 public:
  /** Given a vector and an empty vector, add the sorted vector to target */
  virtual void mysort(const std::vector<T>& source, std::vector<T>* target) = 0;

  Sorter() {}
  virtual ~Sorter() {}

 protected:
  void mycopy(const std::vector<T>& source, std::vector<T>* target) {
    target->clear();

    for (T t : source) {
      target->push_back(t);
    }
  }
};

#endif  // SORTER_H_
