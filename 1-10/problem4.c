#include <stdio.h>
#include <limits.h>

// Palindrome is that from both side, it is the same number
// 18381

int helper(int d, int *p) {
  if(d == 0) return 1;
  if(helper(d / 10, p)) {
    if(d % 10 == *p % 10) {
    *p /= 10;
    return 1;
    }
    else return 0;
  }
  else return 0;
}

int isPali(int d) {
  int k = d;
  return helper(d, &k);
}

int main() {
  int n = 1000;
  int ans = INT_MIN;
  int i1, j1, i, j, temp;
  for(i = n; i > 99; i--){
    for(j = n; j > 99; j--){
      temp = i * j;
      if(isPali(temp)) {
        if(ans < temp) {
          ans = temp;
          i1 = i;
          j1 = j;
          break;
        }
      }
    }
    if(ans > i * n) break;
  }
  printf("%d * %d = %d\n",i1, j1, ans);
  return 0;
}
