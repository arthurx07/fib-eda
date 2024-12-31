/* Modular Exponentiation
*   Input consists of several cases, each one with three natural numbers n, k
*   and m. Assume 2 ≤ n ≤ 30000 and 2 ≤ m ≤ 30000.
*  
*  For every case, print (n^k) mod m;
*/

#include <iostream>

/* Taken from https://en.wikipedia.org/wiki/Modular_exponentiation,
 *  read Direct method, Memory-efficient method plus Right-to-left binary method
 *  (the former one is the implemented here) */
/*
 * Modular exponentiation is: c = (b^e) mod m. From the def. of division, 0 <= c < m.
 *
 * Using the extended Euclidean algorithm:
 * c = (b^e) mod m = (d^-e) mod m,  where e < 0 and b*d ≡ 1 (mod m)
*/
unsigned int modular_pow (unsigned int b, unsigned int e, unsigned int m)
{
  if (m == 1) return 0;

  unsigned int c = 1;
  b %= m;

  for (; e > 0; e >>= 1)
  {
    if (e%2) c = (c*b)%m;
    b = (b*b)%m;
  }
  return c;
}

int main()
{
  unsigned int n, k, m;
  while (std::cin >> n >> k >> m)
  {
    std::cout << modular_pow(n, k, m) << std::endl;
  }
}

/*
Modular exponentiation is efficient to compute, even for very large integers.
On the other hand, computing the modular discrete logarithm – that is, finding
the exponent e when given b, c, and m – is believed to be difficult. This one-way
function behavior makes modular exponentiation a candidate for use in cryptographic
algorithms.
*/
