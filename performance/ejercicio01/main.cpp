// Copyright 2017 Gerardo Teruel

#include <stdio.h>
#include <cstring>

// Order of variables in memory:
// 1. value
// 2. array2
// 3. array3

int main(int argc, char *argv[]) {
  char array1[9];
  char array2[9];
  int value = 10;

  strcpy(array1, "arrayOne");
  strcpy(array2, argv[1]); // If argv[1] > 9, a buffer over flow will occur
                           // and array1 would be modified.

  printf("Array 1 is at %p with value %s\n", array1, array1);
  printf("Array 2 is at %p with value %s\n", array2, array2);
  printf("Value is at %p with value %i\n", &value, value);

  return 0;
}
