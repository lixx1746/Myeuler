#include <stdio.h>

int countDivisor(int n) {
  if(n % 2 == 0) n /= 2;
  int count, ans = 1;
  int p = 2;
  while(n != 1) {
    count = 0;
    while(n % p == 0) {
      n /= p;
      count++;
    }
    ans *= (count + 1);
    p++;
  }
  return ans;
}


int main() {
  int i = 2;
  int left = 1, right = 1;
  int val;
  for(;;i++) {
    val = left * right;
    if(val > 500) break;
    left = right;
    right = countDivisor(i + 1);
  }
  printf("%d\n", (i - 1) * i / 2);
  return 0;
}
