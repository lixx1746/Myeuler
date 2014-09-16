#include <stdlib.h>
#include <stdio.h>
#include "bignum.h"

int main(int argc, char *argv[]) {
  int n;
  int sum = 0;
  if (argc == 1) n = 5;
  else n = atoi(argv[1]);
  bignum cur_ans, cur, ans;
  int_to_bignum(1, &cur_ans);
  for(int i = 1; i <=n; i++) {
    int_to_bignum(i, &cur);
    multiply_bignum(&cur, &cur_ans, &ans);
    cur_ans = ans;
  }
  print_bignum(&ans);
  for(int i = 0; i <= ans.lastdigit; i++) {
    sum += ans.digits[i];
  }

  printf("The ans is %d\n",  sum);
  return 0;
}
