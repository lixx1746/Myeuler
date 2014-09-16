#include <stdio.h>

int main() {
  long dp[21][21];
  dp[0][0] = 1;
  for(int i = 1; i <= 20; i++) dp[0][i] = 1;
  for(int j = 1; j <= 20; j++) dp[j][0] = 1;
  for(int i = 1; i <= 20; i++) {
    for(int j = 1; j <= 20; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }
  printf("%ld\n", dp[20][20]);
  return 0;
}
