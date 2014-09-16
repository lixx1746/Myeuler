#include <stdio.h>

int main() {
  FILE* fp;
  int i = 0, j = 0, carry = 0;
  int data[100][50];
  int ans[50];
  fp = fopen("problem13.dat", "r");
  if(fp == NULL) {
    fprintf(stderr, "cannot open the file");
  }
  while(fscanf(fp, "%1d", &data[i][j++]) != EOF){
    if (j == 50) { i++; j = 0; }
  }
  for(int i = 49; i >= 0; i--) {
    ans[i] = carry;
    for(int j = 0; j < 100; j++) {
      ans[i] += data[j][i];
    }
    carry = ans[i] / 10;
    ans[i] %= 10;
  }
  printf("%d", carry);
  for(int i = 0; i < 50; i++) {
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
