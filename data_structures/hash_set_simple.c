#define SIZE (1 << 22)   // 2,097,152

int key_at[SIZE];
bool used_at[SIZE];   // true if the slot holds a key

void set_init() {
  memset(used_at, false, sizeof(used_at));
}

int set_hash(int key) {
  // return ((key % SIZE) + SIZE) % SIZE;
  return (unsigned) (key & (SIZE - 1));
}

bool set_has(int key) {
  int slot = set_hash(key);
  while (used_at[slot]) {
    if (key_at[slot] == key) {
      return true;
    }
    slot = (slot + 1) % SIZE;
  }
  return false;
}

void set_add(int key) {
  int slot = set_hash(key);
  while (used_at[slot]) {
    slot = (slot + 1) % SIZE;
  }
  key_at[slot] = key;
  used_at[slot] = true;
}

// Usage:
// bool containsDuplicate(int* nums, int n) {
//   set_init();
//   for(int i = 0; i < n; ++i) {
//     bool repeated = set_has(nums[i]);
//     if(repeated) {
//       return true;
//     }
//     set_add(nums[i]);
//   }
//   return false;
// }