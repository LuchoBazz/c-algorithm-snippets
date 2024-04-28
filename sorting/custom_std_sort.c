// #include <stdlib.h>
// #include <time.h>
// typedef long long ll;

#define T_sort ll
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
