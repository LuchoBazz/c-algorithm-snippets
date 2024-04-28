// https://manual.cs50.io
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#ifdef ONLINE_JUDGE // Reference: https://codeforces.com/blog/entry/96344
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define rof(i, n) for (int i = (n)-1; i >= 0; i--)
#define write_endl putchar('\n')
#define abs abs_ll
typedef long long ll;
#define T_minmax ll
T_minmax min(T_minmax a, T_minmax b);
T_minmax max(T_minmax a, T_minmax b);
#define T_abs ll
T_abs abs_ll(T_abs);

#define T_sort ll
int compare(const void *, const void *);
void sort(T_sort *, int, int (*compare_array)(const void *, const void *));

#define INF 1000000000
#define INF64 0x3f3f3f3f3f3f3f3fLL
#define N (200000 + 2)

void solve_one() {
  ;
}

int main(void) {
  int T = 1;
  scanf("%d", &T);
  while (T-- > 0) {
    solve_one();
  }
  return 0;
}

// string:
// int len = strlen(s)
// strcpy, strcat, strcmp, strncpy
// input:
// %s (char*), %d (int), %lld (ll), %c (char), %f (float), %lf (double),
// %u (unsigned), %x (Hexadecimal), %o (Octal)
// output: fprintf(stderr, "%d", num); fflush(stdout)

T_minmax min(T_minmax a, T_minmax b) { return a < b ? a : b; }
T_minmax max(T_minmax a, T_minmax b) { return a > b ? a : b; }
T_abs abs_ll(T_abs num) { return num < 0 ? -num : num; }

int compare(const void *a, const void *b) {
  T_sort first = *(T_sort *)a;
  T_sort second = *(T_sort *)b;
  T_sort diff = first - second;
  return diff == 0 ? 0 : diff < 0 ? -1 : 1;
}
 
void sort(T_sort *array, int n,
          int (*compare_array)(const void *, const void *)) {
  srand(time(NULL));
  T_sort tmp;
  for (int i = 0, j; i < n; i++) {
    j = rand() % (i + 1);
    tmp = array[i], array[i] = array[j], array[j] = tmp;
  }
  qsort(array, n, sizeof(*array), compare_array);
}
// sort(A, n, compare);