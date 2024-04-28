// Taken from rainboy (Rain Jiang) library and modified
#include <stdio.h>
#include <sys/time.h>
// typedef long long ll;

void quick_sort(ll *, int, int);
void init_random();

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
