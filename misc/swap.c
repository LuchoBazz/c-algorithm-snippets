#define T_swap int
void swap(T_swap *first, T_swap *second) {
  T_swap temp = *first;
  *first = *second;
  *second = temp;
}
