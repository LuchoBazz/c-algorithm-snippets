unsigned int Z;

int get_random() { return (Z *= 3) >> 1; }

void init_random() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  Z = tv.tv_sec ^ tv.tv_usec | 1;
}

// at main()
// init_random();
