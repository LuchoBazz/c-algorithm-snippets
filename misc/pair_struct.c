
#define pair_type int
struct pair {
  pair_type first;
  pair_type second;
};

int cmp_pair(pair_type a, pair_type b) {
  return (a == b) ? 0 : (a < b) ? -1 : 1;
}

int compare_pairs(const void *a, const void *b) {
  struct pair *p1 = (struct pair *)a;
  struct pair *p2 = (struct pair *)b;

  pair_type first_cmp = cmp_pair(p1->first, p2->first);
  if (first_cmp != 0) {
    return first_cmp;
  }
  return cmp(p1->second, p2->second);
}
// Usage:
// struct pair pairs[N];
// pairs[0] = (struct pair) {0, 0};
// int n = sizeof(pairs) / sizeof(pairs[0]);
// qsort(pairs, n, sizeof(struct pair), compare_pairs);
