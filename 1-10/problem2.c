#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int N = atoi(argv[1]);
  int sum = 0;
  int cur = 1;
  int next = 2;
  int temp;
  for(;;) {
    if (cur > N) break;
    if (cur % 2 == 0) sum += cur;
    temp = next;
    next += cur;
    cur = temp;
  }
  printf("%d\n", sum);
  return 0;
}
