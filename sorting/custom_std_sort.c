// #include <stdlib.h>
// #include <time.h>

#define sort_type int
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
