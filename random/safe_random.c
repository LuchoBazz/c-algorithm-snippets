unsigned long long Z;

unsigned long long get_random() {
  Z ^= Z << 13ULL;
  Z ^= Z >> 7ULL;
  Z ^= Z << 17ULL;
  return Z;
}

void init_random() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  Z = tv.tv_sec ^ tv.tv_usec | 1;
}

// at main()
// init_random();
