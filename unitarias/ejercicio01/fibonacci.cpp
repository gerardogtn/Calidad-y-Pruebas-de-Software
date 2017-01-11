// Copyright 2017 Gerardo Teruel
int fibonacci(int n) {
  if (n < 1) {
    return 1;
  }
  return n * fibonacci(n - 1);
}
