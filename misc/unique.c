
#define T_unique int
T_unique *make_unique(T_unique *src, int src_sz, int *dest_size) {
  T_unique *src_cloned = (T_unique *)malloc(src_sz * sizeof(T_unique));
  T_unique *dest = (T_unique *)malloc(src_sz * sizeof(T_unique));
  for (int i = 0; i < src_sz; ++i) src_cloned[i] = src[i];
  sort(src_cloned, src_sz, compare);
  dest[0] = src_cloned[0];
  int dest_index = 0;
  for (int i = 0; i < src_sz; ++i) {
    if (src_cloned[i] != dest[dest_index]) {
      dest_index++;
    }
    dest[dest_index] = src_cloned[i];
  }
  *dest_size = dest_index + 1;
  return dest;
}

// int unique_sz = 0;
// int *unique = make_unique(A, n, &unique_sz);
