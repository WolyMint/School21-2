#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
  int n = 0, data[NMAX];
  if (input(&data[0], &n)) {
    output(&data[0], n);

    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
  } else
    printf("n/a");
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

int max(int *a, int n) {
  int max = 0;
  for (int i = 0; i < n; i++) {
    if (max < *(a + i))
      max = *(a + i);
  }
  return max;
}

int min(int *a, int n) {
  int min = 10000000;
  for (int i = 0; i < n; i++) {
    if (min > *(a + i))
      min = *(a + i);
  }
  return min;
}

double mean(int *a, int n) {
  double sum = 0;
  for (int i = 0; i < n; ++i)
    sum += a[i];
  return sum / n;
}

double variance(int *a, int n) {
  double sum = 0;
  double k = mean(a, n);
  for (int i = 0; i < n; ++i)
    sum += (a[i] - k) * (a[i] - k);
  return sum / n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
  char c;
  c = '\n';
  printf("%c", c);
  printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
