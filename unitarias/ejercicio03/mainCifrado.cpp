// Copyright 2017 Gerardo Teruel

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include "CifradoVigenere.hpp"
#include "CifradoCesar.hpp"

void getDictionary(std::vector<std::string>* dictionary) {
  std::ifstream file("diccionario.txt");
  std::string value;
  while (file >> value) {
    std::transform(value.begin(), value.end(), value.begin(), ::toupper);
    dictionary->push_back(value);
  }
}

void getCiphered(std::string& cipherKey, std::string& cipherText) {
  std::ifstream file("encriptado.txt");
  file >> cipherKey;
  std::getline(file, cipherText);
  std::getline(file, cipherText);
  file.close();
}

int main(int argc, char const *argv[]) {
  std::vector<std::string> dictionary;
  std::string cipherKey, cipherText;

  CifradoCesar cesar;
  CifradoVigenere vigenere;

  getDictionary(&dictionary);
  getCiphered(cipherKey, cipherText);

  std::string key = cesar.decipher(cipherKey, dictionary);
  std::cout << "The key is: " << key << '\n';

  std::string text = vigenere.decipher(key, cipherText);
  std::cout << "The text is:\n" << text << '\n';

  return 0;
}
