#define T_bs int
int binary_search(T_bs *source, int size, T_bs target) {
  int left = 0, right = size - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (source[mid] == target) {
      return mid;
    }
    int is_less_than_target = source[mid] < target;
    if (is_less_than_target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}
