
struct pair {
  int first;
  int second;
};

int compare_pairs(const void *a, const void *b) {
  struct pair *p1 = (struct pair *)a;
  struct pair *p2 = (struct pair *)b;

  if (p1->first == p2->first) {
    return p1->second - p2->second;
  }
  return p1->first - p2->first;
}
// Usage:
// struct pair pairs[N];
// pairs[0] = (struct pair) {0, 0};
// int n = sizeof(pairs) / sizeof(pairs[0]);
// qsort(pairs, n, sizeof(struct pair), compare_pairs);
