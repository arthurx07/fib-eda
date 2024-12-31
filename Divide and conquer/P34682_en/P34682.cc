/* Fixed points
 * Let S = x1, …, xn be a sequence of integer numbers such that x1 < … < xn.
 * For every integer number a and every index 1 ≤ i ≤ n, define fa(i) = xi + a.
 * Write a program that, given S and a, tells whether there is some i such that
 *  fa(i) = i.
 */
#include <iostream>
#include <vector>

unsigned int fixed_point(int a, std::vector<int>& v, unsigned int l, unsigned int r)
{
  if (l > r) return 0;

  int m = (l + r)/2;
  int s = v[m] + a;

  if (s < m+1) return fixed_point(a, v, m+1, r);
  int f = 0;
  if (m > 0) f = fixed_point(a, v, l, m-1); // test m > 0, to avoid r < 0
  return (not f and s == m+1) ? m+1 : f; /* test if f is at the left, otherwise print m+1 */
}

unsigned int fixed_point(int a, std::vector<int>& v)
{
  return fixed_point(a, v, 0, v.size()-1);
  /* for (unsigned int i = 0; i < v.size(); ++i) {
  *   if (a + v[i] >=0 and (unsigned int)a + v[i] == i+1) return i+1;
  * }
  * return 0; */
}

int main()
{
  unsigned int n, m;
  for (unsigned int i = 1; std::cin >> n; ++i)
  {
    std::vector<int> S(n);
    for (unsigned int j = 0; j < n; ++j) std::cin >> S[j];

    std::cin >> m;
    std::cout << "Sequence #" << i << std::endl;
    for (unsigned int j = 0; j < m; ++j)
    {
      int a, f;
      std::cin >> a;

      if ((f = fixed_point(a, S)) > 0) std::cout << "fixed point for " << a << ": " << f << std::endl;
      else std::cout << "no fixed point for " << a << std::endl;
    }
    std::cout << std::endl;
  }
}
