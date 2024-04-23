#include <stdio.h> // https://manual.cs50.io
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/time.h>

#ifdef ONLINE_JUDGE // Reference: https://codeforces.com/blog/entry/96344
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define rof(i, n) for (int i = (n)-1; i >= 0; i--)
#define INF 1000000000
#define INF64 0x3f3f3f3f3f3f3f3fLL
#define ll long long
#define write_endl putchar('\n')

ll min(ll, ll);
ll max(ll, ll);
void quick_sort(ll *, int, int);
void init_random();

#define N (200000 + 5)

int n, m;
// char s[N];
ll A[N], B[N];

void solve_one() {
  ;
}

int main(void) {
  init_random();

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

// Taken from rainboy (Rain Jiang) library and modified
unsigned int Z;
int get_random() { return (Z *= 3) >> 1; }

void init_random() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  Z = tv.tv_sec ^ tv.tv_usec | 1;
}

void quick_sort(ll *array, int left, int right) { // [left, right)
  while (left < right) {
    int pivot_index = left, low = left, high = right;
    ll pivot_value = array[left + get_random() % (right - left)], temp;

    while (low < high) {
      if (array[low] == pivot_value)
        low++;
      else if (array[low] < pivot_value) {
        temp = array[pivot_index];
        array[pivot_index] = array[low];
        array[low] = temp;
        pivot_index++;
        low++;
      } else {
        high--;
        temp = array[low];
        array[low] = array[high];
        array[high] = temp;
      }
    }
    quick_sort(array, left, pivot_index);
    left = high;
  }
}
