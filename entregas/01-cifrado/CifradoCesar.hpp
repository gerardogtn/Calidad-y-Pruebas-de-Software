// Copyright 2017 Gerardo Teruel
#ifndef UNITARIAS_EJERCICIO03_CIFRADOCESAR_H_
#define UNITARIAS_EJERCICIO03_CIFRADOCESAR_H_

#include <stdexcept>
#include <algorithm>
#include <string>
#include <vector>
#include "Cifrado.hpp"

class CifradoCesar : public Cifrado {
 private:
  const std::vector<std::string> dictionary;

 public:
  explicit CifradoCesar(const std::vector<std::string>& dictionary)
      : dictionary(dictionary) {}

  virtual ~CifradoCesar() {}

  virtual std::string decipher(const std::string& cipher) {
    for (int i = 0; i < 26; i++) {
      std::string word = "";
      for (int j = 0; j < cipher.size(); j++) {
        word.append(1, (cipher[j] + i - 64) % 26 + 64);
      }
      if (std::find(dictionary.begin(), dictionary.end(), word) != dictionary.end()) {
        return word;
      }
    }
    throw std::runtime_error("Cannot find key");
  }
};

#endif  // UNITARIAS_EJERCICIO03_CIFRADOCESAR_H_
