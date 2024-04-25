// #include <stdlib.h>
// #include <time.h>
// typedef long long ll;

#define sort_type ll
int compare(const void *a, const void *b) {
  sort_type first = *(sort_type *)a;
  sort_type second = *(sort_type *)b;
  sort_type diff = first - second;
  return diff == 0 ? 0 : diff < 0 ? -1 : 1;
}
 
void sort(sort_type *array, int n,
          int (*compare_array)(const void *, const void *)) {
  srand(time(NULL));
  sort_type tmp;
  for (int i = 0, j; i < n; i++) {
    j = rand() % (i + 1);
    tmp = array[i], array[i] = array[j], array[j] = tmp;
  }
  qsort(array, n, sizeof(*array), compare_array);
}
// sort(A, n, compare);
