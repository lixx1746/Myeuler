#include <stdio.h>

int main() {
  const int sum = 1000;
  for (int a = 1; a <= sum / 3; a++) {
    for (int b = a + 1; b <= sum / 2; b++) {
      int c = sum - a - b;
      if (a * a + b * b == c * c) {
        printf("a = %d, b = %d, c = %d\n", a, b, c);
        printf("%d\n", a * b * c);
        return 0;
      }
    }
  }
  return -1;
}
