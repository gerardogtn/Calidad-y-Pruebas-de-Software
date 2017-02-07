// Copyright 2017 Gerardo Teruel

#include <cstdio>
#include <cstring>

// If you overflow temp, then you'd modify out variable. Thus getting a one,
// and indicating a valid authentication
int fun(char* pass) {
  int out = 0;
  char temp[8];
  strcpy(temp, pass);

  if (strcmp(temp, "1234567") == 0) {
    out = 1;
  }

  return out;
}

int main(int argc, char *argv[]) {
  if (fun(argv[1])) {
    printf("%s\n", "Access granted");
  } else {
    printf("%s\n", "Access denied");
  }
  return 0;
}
