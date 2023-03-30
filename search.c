#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
void output(int a);
double mean(int *a, int n);
double variance(int *a, int n);
double rule(int *a, int n);

int check(int *a, int n, double rule_v);

int main() {
  int n = 0, data[NMAX];
  if (input(&data[0], &n)) {
    output(check(&data[0], n, rule(&data[0], n)));
  } else
    printf("n/a");
  //  printf("%f",rule(&data[0],n));
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

void output(int a) { printf("%d", a); }

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

double rule(int *a, int n) {
  double k = mean(a, n) + 3 * sqrt(variance(a, n));
  return k;
}

int check(int *a, int n, double rule_v) {
  int num = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 0 && a[i] >= mean(a, n) && a[i] <= rule_v && a[i] != 0) {
      num = a[i];
      break;
    }
  }
  return num;
}
