#include <stdio.h>

static int data[20][20];

typedef enum DIRECTION {LEFTDOWN, DOWN, RIGHTDOWN, RIGHT} DIRECTION;
static inline int max(int a, int b) {return a > b ? a : b;}

int isAvai(int i, int j, DIRECTION d) {
  int result;
  if (d == LEFTDOWN) result = (j >= 3 && i <= 16);
  else if (d == DOWN) result = (i <= 16);
  else if (d == RIGHTDOWN) result = (j <= 16 && i <= 16);
  else result = (j <= 16);
  return result;
}

int get(int i, int j, DIRECTION d) {
  int a, b, c;
  if (d == LEFTDOWN) {a = data[i + 3][j - 3]; b = data[i + 2][j - 2]; c = data[i + 1][j - 1];}
  else if (d == DOWN) {a = data[i + 3][j]; b = data[i + 2][j]; c = data[i + 1][j];}
  else if (d == RIGHTDOWN) {a = data[i + 3][j + 3]; b = data[i + 2][j + 2]; c = data[i + 1][j + 1];}
  else {a = data[i][j + 3]; b = data[i][j + 2]; c = data[i][j + 1];}
  return a * b * c * data[i][j];
}

int main() {
  FILE* f;
  int i = 0, j = 0, d;
  int ans = 0;
  f = fopen("problem11.dat", "r");
  while(fscanf(f,"%d", &d) != EOF) {
    data[i][j++] = d;
    if (j % 20 == 0) {
      i++;
      j = 0;
    }
  }
  fclose(f);

  for(int i = 0; i < 20; i++){
    for(int j = 0; j < 20; j++){
      if(isAvai(i, j, LEFTDOWN)) ans = max(ans, get(i, j, LEFTDOWN));
      if(isAvai(i, j, DOWN)) ans = max(ans, get(i, j, DOWN));
      if(isAvai(i, j, RIGHTDOWN)) ans = max(ans, get(i, j, RIGHTDOWN));
      if(isAvai(i, j, RIGHT)) ans = max(ans, get(i, j, RIGHT));
    }
  }
  printf("%d\n", ans);
  return 0;
}
