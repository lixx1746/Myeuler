#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
  int n = atoi(argv[1]);
  long long sqOFsu = n * (n + 1) * (2 * n + 1) / 6;
  long long temp = n * (n + 1) / 2;
  long long suOFsq = temp * temp;
  printf("%lld\n", suOFsq - sqOFsu);
  return 0;
}
