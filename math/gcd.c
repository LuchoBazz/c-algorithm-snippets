#define T_gcd int
T_gcd gcd(T_gcd a, T_gcd b) {
  return (b == 0) ? a : gcd(b, a % b);
}
