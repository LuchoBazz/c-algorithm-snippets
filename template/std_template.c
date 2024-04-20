#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define rof(i, n) for (int i = (n)-1; i >= 0; i--)
#define ll long long
#define endl "\n"

ll min(ll, ll);
ll max(ll, ll);
void sort(ll *, int, int);
void init_random();

#define N (200000 + 5)

int n, m;
// char s[N];
ll A[N], B[N];

void solve_one() {
  ;
}

int main() {
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
// %s (char*) %d (int) %lld (ll) %c (char) %f (float) %lf (double) %u (unsigned) %x (Hexadecimal) %o (Octal)

ll min(ll a, ll b) { return a < b ? a : b; }
ll max(ll a, ll b) { return a > b ? a : b; }

unsigned int Z;
int get_random() { return (Z *= 3) >> 1; }

void init_random() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  Z = tv.tv_sec ^ tv.tv_usec | 1;
}

void sort(ll *array, int left, int right) { // [left, right)
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
    sort(array, left, pivot_index);
    left = high;
  }
}
