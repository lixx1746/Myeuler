#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "str2lld.h"

// depend on str2lld.c
// any number will be factored into prime

int main(int argc, char** argv) {
  long long n;
  if (argc == 1) n = 10;
  else n = str2lld(argv[1]);
  // printf("%lld\n", n);
  int l = 2;
  int ans, flag;
  while(n > 1) {
    flag = 0;
    while (n % l == 0) {
      n /= l;
      if(!flag && ans < l) {
        ans = l;
        flag = !flag;
      }
    }
    l++;
  }
  printf("%d\n", ans);
  return ans;
}
