#include <iostream>

/* P(k)= P(k/2) + 0(1), α = log2(1) = 0, k = 0
=> α=k => P(n) = 0(logn) */
// Algorisme d'exponenciació ràpida amb cost logarítmic
double pow (double x, int k)
{
  if (k == 0) return 1;

  double y = pow(x, k/2);
  if (not k%2) return y*y;
  return y*y*x;
}

int main()
{
  int k;
  double n;

  while (std::cin >> n >> k)
    std::cout << pow(n, k) << std::endl;
}
