#include <stdio.h>

/* find the number divisors of n, including 1 and itself */

int find_num_of_divisor(int n) {
  int p = 2;
  int ans = 1, count = 1;
  while(n % p == 0) {
    n /= p;
    count++;
  }
  ans *= count;
  p++;
  while(n != 1) {
    count = 1;
    while(n % p == 0) {
      n /= p;
      count++;
    }
    ans *= count;
    p += 2;
  }
  return ans;
}
