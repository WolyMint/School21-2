#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
  int n = 0, data[NMAX];
  if (input(&data[0], &n)) {
    squaring(&data[0], n);
    output(&data[0], n);
  }
  return 0;
}

int input(int *a, int *n) {
  int t = 1, trash;
  if (scanf("%d.%d", n, &trash) == 1) {
    for (int i = 0; i < *n && t; i++) {
      int tmp;
      if (scanf("%d.%d", &tmp, &trash) == 1) {
        *(a + i) = tmp;
        t = 1;
      } else
        t = 0;
    }
  } else
    printf("n/a");
  if (t != 1)
    printf("n/a");
  return t;
}

void output(int *a, int n) {

  for (int i = 0; i < n; i++) {
    if (i == n - 1)
      printf("%d", *(a + i));
    else
      printf("%d ", *(a + i));
  }
}
void squaring(int *a, int n) {
  for (int i = 0; i < n; i++) {
    *(a + i) = *(a + i) * *(a + i);
  }
}
