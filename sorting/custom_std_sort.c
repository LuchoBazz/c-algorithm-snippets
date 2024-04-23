// #include <stdlib.h>
// #include <time.h>

#define sort_type int
sort_type compare(const void *a, const void *b) {
  sort_type ia = *(sort_type *)a;
  sort_type ib = *(sort_type *)b;
  return ia - ib;
}

void sort(sort_type *array, int n) {
  srand(time(NULL));
  sort_type tmp;
  for (int i = 0, j; i < n; i++) {
    j = rand() % (i + 1);
    tmp = array[i], array[i] = array[j], array[j] = tmp;
  }
  qsort(array, n, sizeof *array, compare);
}
