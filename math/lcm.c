#define T_lcm int
T_lcm lcm(T_lcm a, T_lcm b) {  
  return (a * b) / gcd(a, b);  
}
