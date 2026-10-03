#define SIZE   (2 << 14)   // 32768 = 2^15, table capacity
#define EMPTY -1

int key_at[SIZE];
int value_at[SIZE];

void map_init() {
  memset(value_at, EMPTY, sizeof(value_at));
}

int map_hash(int key) {
  return ((key % SIZE) + SIZE) % SIZE;
}

int map_get(int key) {
  int slot = map_hash(key);
  while (value_at[slot] != EMPTY) {
    if (key_at[slot] == key) {
      return value_at[slot];
    }
    slot = (slot + 1) % SIZE;
  }
  return EMPTY;
}

void map_set(int key, int value) {
  int slot = map_hash(key);
  while (value_at[slot] != EMPTY) {
    slot = (slot + 1) % SIZE;
  }
  key_at[slot] = key;
  value_at[slot] = value;
}

// Usage:
// int* twoSum(int* nums, int n, int target, int* returnSize) {
//   int* ans = malloc(2 * sizeof(int));
//   *returnSize = 2;
//   map_init();

//   for (int i = 0; i < n; i++) {
//     int prev = map_get(target - nums[i]);   // index of the complement
//     if (prev != EMPTY) {
//       ans[0] = prev;
//       ans[1] = i;
//       return ans;
//     }
//     map_set(nums[i], i);
//   }
//   return ans;
// }