unsigned long long Z;

unsigned long long get_random() {
  Z ^= Z << 13LL;
  Z ^= Z >> 7LL;
  Z ^= Z << 17LL;
  return Z;
}

void init_random() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  Z = tv.tv_sec ^ tv.tv_usec | 1;
}

// at main()
// init_random();
