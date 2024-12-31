/* Two coins of each kind (1)
 * Given a natural number x and n different coin values c1 … cn, compute in how
 *  many ways it is possible to achieve change x by using each value at most twice.
 *  Here, two coins with the same value are considered different.
 * ex: x = 4, c1 = 1, c2 = 2 => 4 = 1 + 1' + 2 = 1 + 1' + 2' = 2 + 2'
 *
 * Assume 1 ≤ n ≤ 20, 1 ≤ ci ≤ x ≤ 1000, and that all ci are different.
 * For every case print, in lexicographic order, all possible ways to exactly
 *  achieve change x by using each value at most twice. Print every solution
 *  with its values sorted from small to big. In doing that, assume
 *  1 < 1′ < 2 < 2′ < …. Use “1p” to print 1′, etcetera. Print a line with 10
 *  dashes at the end of every case.
 *
 * Hint: a simply pruned backtracking should be enough.
*/

#include <algorithm>
#include <iostream>
#include <vector>

void print(int x, std::vector<int>& A, int i)
{
  std::cout << x << " = ";
  for (int k = 0; k < i; ++k) {
    if (k > 0) std::cout << " + ";
    if (A[k] < 0) std::cout << -A[k] << 'p';
    else std::cout << A[k];
  }
  std::cout << std::endl;
}

// Prunings:
// 1. If sum > x, stop searching.

// i: position in solution vector A
// j: position in candidates vector c 
// first: true if both values c[j] have never been visited
// In A the second time a value is used is codified in its negative value (xp = -x).
void combinations(int x, std::vector<int>& A, std::vector<int>& c, int sum, int i, int j, bool first)
{
  if (sum == x) print(x, A, i);
  else if (sum < x and i < int(A.size()) and j < int(c.size())) {
    if (first) {
      A[i] = c[j];
      combinations(x, A, c, sum + c[j], i+1, j, false); // possibilities using c[j] (and possibly c[j]p, which will be decided later)
    }
    A[i] = -c[j];
    combinations(x, A, c, sum + c[j], i+1, j+1, true); // possibilities using only c[j]p

    combinations(x, A, c, sum, i, j+1, true); // possibilities without using c[j], current A[i]
  }
}

void combinations(int x, std::vector<int>& c)
{
  std::vector<int> A(2*c.size());
  combinations(x, A, c, 0, 0, 0, true);
}

int main()
{
  int x, n;
  while (std::cin >> x >> n) {
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) std::cin >> c[i];
    std::sort(c.begin(), c.end());

    combinations(x, c);
    std::cout << "----------" << std::endl;
  }
}
