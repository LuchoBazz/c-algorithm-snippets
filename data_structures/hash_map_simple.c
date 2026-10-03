#define SIZE   (2 << 21)   // 2,097,152
#define EMPTY -1

int key_at[SIZE];
int value_at[SIZE];

void map_init() {
  memset(value_at, EMPTY, sizeof(value_at));
}

int map_hash(int key) {
  // return (unsigned) (key & (SIZE - 1));
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
// bool containsDuplicate(int* nums, int n) {
//   init_map();
//   for(int i = 0; i < n; ++i) {
//     bool repeated = map_get(nums[i]) != -1;
//     if(repeated) return true;
//     map_set(nums[i], i);
//   }
//   return false;
// }