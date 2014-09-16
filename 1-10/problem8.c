#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#define NUM 1000
static int data[NUM];

static inline long long max(int a, int b) { return a > b ? a : b;}

long long product(int start, int end) {
  long long ans  = 1;
  int i = start;
  for (; i <  end; i++) ans  *= data[i];
  return ans;
}



int main(int argc, char** argv) {
  int n;
  int d;
  int i = 0;
  if(argc == 1) n = 13;
  else n = atoi(argv[1]);
  printf("%d\n", n);
  FILE *fp;
  long long ans = INT_MIN;
  long long window;
  fp = fopen(argv[2], "r");

  if (fp == NULL) {
    fprintf(stderr, "Can't open the input file'");
    exit(1);
  }
  while (fscanf(fp, "%d", &d) != EOF){
    data[i++] = d;
  }

  fclose(fp);
  /* Critical part, using slice window */
  window = product(0, n);
  for(int j = n; j < NUM; j++) {
    /* if window is 0, and data[j - n] is also 0, then that may be the reason the cause window to be zero */
    if (window == 0 && data[j - n] == 0) window = product(j - n + 1, j + 1);
    else if (window == 0) continue;
    else window = window / data[j - n] * data[j];
    ans = max(ans, window);
  }
  printf("%lld\n", ans);
  return 0;

}
