#include <stdio.h>
#include <stdlib.h>


//find the smallest multiple
//The lowest common multiple

int gcd(int m , int n) {
  int t;
  while(n != 0){
    t = n;
    n = m % n;
    m = t;
  }
  return m;
}

int main(int argc, char** argv) {
  int n;
  if(argc == 1) n = 20;
  else n = atoi(argv[1]);
  long long ans = 1;
  for(int i = 1; i <= n; i++){
    ans = (ans * i) / gcd(ans, i);
  }
  printf("The smallest multiple is %lld\n", ans);
  return 0;
}
