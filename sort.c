#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);

void sort(int *a, int n);

int main() {
  int n = 10, data[NMAX];
  if (input(data, &n)) {
    sort(data, n);
    output(data, n);
  } else
    printf("n/a");
  return 0;
}

int input(int *a, int *n) {

  int t = 1, trash;
  for (int i = 0; i < *n && t; i++) {
    int tmp;
    if (scanf("%d.%d", &tmp, &trash) == 1) {
      *(a + i) = tmp;
      t = 1;
    } else
      t = 0;
  }
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

void sort(int *a, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (a[j + 1] < a[j]) {
        int tmp = a[j + 1];
        a[j + 1] = a[j];
        a[j] = tmp;
      }
    }
  }
}
