#include <stdio.h>
#define N 1000000

static int dp[N + 1];

int main() {
  dp[0] = 0;
  dp[1] = 1;
  int ans, count = 1;
  int max_len = 0;
  long long val, i = 2;
  for(; i <= N; i++) {
    val = i;
    count = 0;
    while(val != 1 && val >= i) {
      if (val % 2 == 0) val /= 2;
      else val = 3 * val + 1;
      count++;
    }
    dp[i] = dp[val] + count;
    if(max_len < dp[i]) {
      max_len = dp[i];
      ans = i;
    }
  }
  printf("The start number is %d, The length is %d\n", ans, max_len);
  return 0;
}
