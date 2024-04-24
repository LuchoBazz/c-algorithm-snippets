
#define pb_type int
void push_back(pb_type **vec, int *len, pb_type value) {
  int index = (*len);
  int is_power_of_two = (index & (index - 1)) == 0;
  if (index >= 2 && is_power_of_two) {
    *vec = (pb_type *)realloc(*vec, index * 2 * sizeof(pb_type));
  }
  (*vec)[index] = value;
  (*len)++;
}


// -----------------------------------------------------------------
// Vector
// int v_len = 0;
// int *vec = (int *) malloc(2 * sizeof(int));
// push_back(&vec, &v_len, 1);
// push_back(&vec, &v_len, 2);
// for (int i = 0; i < v_len; ++i) printf("%d ", vec[i]);
// Ouput: 1 2
// -----------------------------------------------------------------
// Matrix NxM
// #define N 2
// int *grid[N];
// int grid_cnt[N] = {0};
//
// for (int i = 0; i < N; ++i) {
//   grid[i] = (int *)malloc(2 * sizeof(*grid[i]));
// }
// 
// push_back(&grid[0], &grid_cnt[0], 10);
// push_back(&grid[0], &grid_cnt[0], 20);
// push_back(&grid[1], &grid_cnt[1], 30);
// push_back(&grid[1], &grid_cnt[1], 40);
// 
// for (int i = 0; i < N; ++i) {
//   for (int j = 0; j < grid_cnt[i]; ++j) printf("%d ", grid[i][j]);
//   putchar('\n');
// }
// Ouput:
// 10 30 
// 20 40 
