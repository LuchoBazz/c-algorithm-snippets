
#define T_pair int // only supports numeric values yet
struct pair {
  T_pair first;
  T_pair second;
};

int cmp_pair(T_pair a, T_pair b) {
  return (a == b) ? 0 : (a < b) ? -1 : 1;
}

int compare_pairs(const void *a, const void *b) {
  struct pair *p1 = (struct pair *)a;
  struct pair *p2 = (struct pair *)b;

  T_pair first_cmp = cmp_pair(p1->first, p2->first);
  if (first_cmp != 0) {
    return first_cmp;
  }
  return cmp(p1->second, p2->second);
}
// Usage:
// struct pair pairs[N];
// int n = 0;
// pairs[n++] = (struct pair) {0, 0};
// qsort(pairs, n, sizeof(struct pair), compare_pairs);
