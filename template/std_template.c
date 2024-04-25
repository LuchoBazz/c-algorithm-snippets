#include <assert.h>
#include <math.h>
#include <stdio.h> // https://manual.cs50.io
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
ll min(ll, ll);
ll max(ll, ll);
ll abs_ll(ll);
#define sort_type ll
sort_type compare(const void *, const void *);
void sort(sort_type *, int, sort_type (*compare_array)(sort_type, sort_type));

#define INF 1000000000
#define INF64 0x3f3f3f3f3f3f3f3fLL
#define N (200000 + 5)

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

ll min(ll a, ll b) { return a < b ? a : b; }
ll max(ll a, ll b) { return a > b ? a : b; }
ll abs_ll(ll num) { return num < 0 ? -num : num; }

sort_type compare(const void *a, const void *b) {
  sort_type first = *(sort_type *)a;
  sort_type second = *(sort_type *)b;
  return first - second;
}

void sort(sort_type *array, int n,
          sort_type (*compare_array)(sort_type, sort_type)) {
  srand(time(NULL));
  sort_type tmp;
  for (int i = 0, j; i < n; i++) {
    j = rand() % (i + 1);
    tmp = array[i], array[i] = array[j], array[j] = tmp;
  }
  qsort(array, n, sizeof *array, compare_array);
}
// sort(A, n, compare);
