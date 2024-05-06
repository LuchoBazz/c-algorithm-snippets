// Taken from rainboy (Rain Jiang) library and modified
// Reference: https://codeforces.com/contest/1970/submission/259673069

#define SIZE_N 1000
#define SIZE_K 30
#define SIZE_M (SIZE_N * SIZE_N)
#define SIZE_L (SIZE_N * SIZE_K)
#define MAP_MOD 0x7fffffff

int X_CONSTANT = 123454321;

int *map_keys[SIZE_M], *map_values[SIZE_M], map_size[SIZE_M],
    map_capacity[SIZE_M];

int compute_hash(int key) {
  return (long long)key * X_CONSTANT % MAP_MOD % SIZE_M;
}

int map_put(int key, int value) {
  int hashed_key = compute_hash(key);

  for (int i = map_size[hashed_key]; i--;) {
    if (map_keys[hashed_key][i] == key) {
      // map_values[hashed_key][i] += value; // return 0 o 1?
      return 0;
    }
  }
  int index = map_size[hashed_key]++;
  if (index == map_capacity[hashed_key]) {
    map_capacity[hashed_key] *= 2;
    map_keys[hashed_key] = (int *)realloc(map_keys[hashed_key], map_capacity[hashed_key] * sizeof *map_keys[hashed_key]);
    map_values[hashed_key] = (int *)realloc(map_values[hashed_key], map_capacity[hashed_key] * sizeof *map_values[hashed_key]);
  }
  map_keys[hashed_key][index] = key;
  map_values[hashed_key][index] = value;
  return 1;
}

#define MAP_NEUTRO 0x7fffffff
int get(int key) {
  int hashed_key = compute_hash(key);

  for (int i = map_size[hashed_key]; i--;) {
    if (map_keys[hashed_key][i] == key)
      return map_values[hashed_key][i];
  }
  return MAP_NEUTRO;
}

int map_contains_key(int key) {
  return get(key) != MAP_NEUTRO;
}

void map_clear() {
  // TODO:
}

void map_remove(int key) {
  int hashed_key = compute_hash(key), index;

  for (index = map_size[hashed_key]; index--;) {
    if (map_keys[hashed_key][index] == key) {
      map_size[hashed_key]--;
      while (index < map_size[hashed_key])
        map_keys[hashed_key][index] = map_keys[hashed_key][index + 1],
        map_values[hashed_key][index] = map_values[hashed_key][index + 1], index++;
      return;
    }
  }
}

int main() {

  for (int index = 0; index < SIZE_M; index++) {
    map_capacity[index] = 2;
    map_keys[index] =
        (int *)malloc(map_capacity[index] * sizeof *map_keys[index]);
    map_values[index] =
        (int *)malloc(map_capacity[index] * sizeof *map_values[index]);
    map_size[index] = 0;
  }

  map_put(1, 10);
  map_put(1, 10);
  map_put(2, 20);
  map_put(3, 30);

  cout << "get(1): " << get(1) << endl;
  cout << "get(2): " << get(2) << endl;
  cout << "get(3): " << get(3) << endl;
  cout << "get(4): " << get(4) << endl;

  cout << "map_remove(1):" << endl;
  map_remove(1);
  cout << "get(1): " << get(1) << endl;
  cout << "get(2): " << get(2) << endl;
  cout << "get(3): " << get(3) << endl;
  cout << "get(4): " << get(4) << endl;
  
  int * num = NULL;
  
  if(num != NULL) free(num);
  
  printf((num == NULL) ? "YES" : "NO");

  return 0;
}
