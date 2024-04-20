// #define ll long long

void unique(ll *source, int src_size, ll *destination, int *dest_size) {
  // sort(source, 0, src_size); // requires that source is sorted
  destination[0] = source[0];
  int dest_index = 0;
  for(int i = 0; i < src_size; ++i) {
    if (source[i] != destination[dest_index]) {
      dest_index++;
    }
    destination[dest_index] = source[i];
  }
  *dest_size = dest_index + 1;
}
