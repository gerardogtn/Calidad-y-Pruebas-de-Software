// Copyright 2017 Gerardo Teruel
#ifndef UNITARIAS_EJERCICIO03_CIFRADOCESAR_H_
#define UNITARIAS_EJERCICIO03_CIFRADOCESAR_H_

#include <stdexcept>
#include <algorithm>
#include <string>
#include <vector>

class CifradoCesar {
 public:
  std::string decipher(const std::string& cipher, const std::vector<std::string>& dict) {
    for (int i = 0; i < 26; i++) {
      std::string word = "";
      for (int j = 0; j < cipher.size(); j++) {
        word.append(1, (cipher[j] + i - 64) % 26 + 64);
      }
      if (std::find(dict.begin(), dict.end(), word) != dict.end()) {
        return word;
      }
    }
    throw std::runtime_error("Cannot find key");
  }
};

#endif  // UNITARIAS_EJERCICIO03_CIFRADOCESAR_H_
