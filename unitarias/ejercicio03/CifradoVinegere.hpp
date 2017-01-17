// Copyright 2017 Gerardo Teruel
#ifndef UNITARIAS_EJERCICIO03_CIFRADOVINEGERE_H_
#define UNITARIAS_EJERCICIO03_CIFRADOVINEGERE_H_

#include <string>

class CifradoVinegere {
  std::string decipher(const std::string& key, const std::string& cipher) {
    std::string out = "";
    int special = 0;

    for (int i = 0; i < cipher.size(); i++) {
      if (cipher[i] == '.' || cipher[i] == ' ') {
        special++;
        out += cipher[i];
      } else {
        int index = cipher[i] - key[(i - special) % 26];
        out += index + 65;
      }
    }

    return out
  }
};

#endif  // UNITARIAS_EJERCICIO03_CIFRADOVINEGERE_H_
