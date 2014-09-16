#include <stdio.h>
#include <assert.h>
#include "str2lld.h"

int isDigit(char c) {return c > '0' && c < '9';}

long long str2lld(const char* str) {
  const char* p;
  p = str;
  long long sum = 0;  // forget initial the sum to 0;
  int temp;
  for(; *p; ++p){
    // assert(isDigit(*p));
    temp = *p - '0';
    // printf("%d\n", temp);
    sum = 10 * sum + temp;
  }
  //printf("%lld\n", sum);
  return sum;
}
