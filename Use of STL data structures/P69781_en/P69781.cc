/* Let us define sequences similar to those of Collatz with two parameters x
 *  and y. Given a number n, the algorithm to get the next number is:
   * if n is even, we move to n/2 + x;
   * otherwise, we move to 3n + y. 
 *
 * The standard Collatz sequence corresponds to x = 0 and y = 1.
 *
 * Assume x < 1000, y < 1000, y%2 != 0, n <= 10^8
 * Stop in the first number that strictly exceeds 10^8
 */

#include <iostream>
#include <map>

int collatz(std::map<int, int> &m, int x, int y, int n, int c = 1) // default value for c is 1 (the start)
{
  if (n > 1e8) return n; // 1e8 is the limit for searching
  if (m[n] != 0) return c - m[n]; // meaning we are in a cycle of size c - m[n] (actual position minus position of repeated number)

  m[n] = c; // we set actual position
  if (n%2) return collatz(m, x, y, 3*n + y, c + 1); // n is odd
  else return collatz(m, x, y, n/2 + x, c + 1); // n is even
}

int main()
{
  int x, y, n;
  while (std::cin >> x >> y >> n)
  {
    std::map<int, int> m;
    std::cout << collatz(m, x, y, n) << std::endl;

    /* Alternative:
    int c;
    for (c = 1; m[n] == 0 and n <= 1e8; ++c)
    {
      m[n] = c;
      if (n%2) n = 3*n + y;
      else n = n/2 + x;
    }
    if (m[n] != 0) std::cout << c - m[n] << std::endl;
    else std::cout << n << std::endl;
    */
  }
}
