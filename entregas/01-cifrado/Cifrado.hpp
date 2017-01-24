// Copyright 2017 Gerardo Teruel
#ifndef UNITARIAS_EJERCICIO03_CIFRADO_H_
#define UNITARIAS_EJERCICIO03_CIFRADO_H_

#include <string>

class Cifrado {
 public:
  virtual ~Cifrado() {}
  virtual std::string decipher(const std::string& cipher) = 0;
};

#endif  // UNITARIAS_EJERCICIO03_CIFRADO_H_
