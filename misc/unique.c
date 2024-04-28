
#define unique_type int
unique_type *make_unique(unique_type *src, int src_sz, int *dest_size) {
  unique_type *src_cloned = (unique_type *)malloc(src_sz * sizeof(unique_type));
  unique_type *dest = (unique_type *)malloc(src_sz * sizeof(unique_type));
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
