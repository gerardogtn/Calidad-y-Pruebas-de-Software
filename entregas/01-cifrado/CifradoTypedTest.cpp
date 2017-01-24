// Copyright 2017 Gerardo Teruel
#include <string>
#include <utility>
#include <vector>
#include "gmock/gmock.h"
#include "Cifrado.hpp"
#include "CifradoCesar.hpp"
#include "CifradoVigenere.hpp"

using testing::Eq;
using testing::TestWithParam;
using testing::Values;

typedef Cifrado* factoryMethod();

Cifrado* cesar() {
  std::vector<std::string> dictionary {"GARDEN"};
  return new CifradoCesar(dictionary);
}

Cifrado* vigenere() {
  return new CifradoVigenere("BANANA");
}

class ACifrado : public TestWithParam<std::pair<factoryMethod*, std::string>> {
};

TEST_P(ACifrado, Decifrado) {
  Cifrado* cifrado = (*(GetParam().first))();
  std::string cipher = GetParam().second;

  ASSERT_THAT(cifrado->decipher(cipher), Eq("GARDEN"));

  delete cifrado;
}

INSTANTIATE_TEST_CASE_P(CifradoTest, ACifrado, Values(std::make_pair(&cesar, "RLCOPY"), std::make_pair(&vigenere, "HAEDRN")));
