// typedef long long ll;

int binary_search(ll *source, int size, ll target) {
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
