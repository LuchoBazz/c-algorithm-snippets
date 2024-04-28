
#define T_pb int
void push_back(T_pb **vec, int *len, T_pb value) {
  int index = (*len)++;
  int is_power_of_two = (index & (index - 1)) == 0;
  if (index == 0) {
    *vec = (T_pb *)malloc(2 * sizeof(T_pb));
  } else if (index >= 2 && is_power_of_two) {
    *vec = (T_pb *)realloc(*vec, index * 2 * sizeof(T_pb));
  }
  (*vec)[index] = value;
}


// -----------------------------------------------------------------
// Vector
// int v_len = 0;
// int *vec = NULL;
// push_back(&vec, &v_len, 1);
// push_back(&vec, &v_len, 2);
// for (int i = 0; i < v_len; ++i) printf("%d ", vec[i]);
// free(vec);
// Ouput: 1 2
// -----------------------------------------------------------------
// Matrix NxM
// #define N 2
// int *grid[N];
// int grid_cnt[N] = {0};
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
// for (int i = 0; i < ...; ++i) free(grid[i]);
// Ouput:
// 10 30 
// 20 40 
