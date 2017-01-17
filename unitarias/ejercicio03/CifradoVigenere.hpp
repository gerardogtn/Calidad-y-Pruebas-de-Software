// Copyright 2017 Gerardo Teruel
#ifndef UNITARIAS_EJERCICIO03_CIFRADOVIGENERE_H_
#define UNITARIAS_EJERCICIO03_CIFRADOVIGENERE_H_

#include <string>

class CifradoVigenere {
 public:
  std::string decipher(const std::string& key, const std::string& cipher) {
    std::string out = "";
    int special = 0;

    for (int i = 0; i < cipher.size(); i++) {
      if (cipher[i] == '.' || cipher[i] == ' ') {
        special++;
        out.append(1, cipher[i]);
      } else {
        /** int to be able to hold negative numbers */
        int c = cipher[i] - key[(i - special) % key.size()];

        if (c < 0) {
          out.append(1, 91 + c);
        } else {
          out.append(1, (c % 26) + 65);
        }
      }
    }

    return out;
  }
};

#endif  // UNITARIAS_EJERCICIO03_CIFRADOVIGENERE_H_
