/* Two coins of each kind (3)
 * Given a number x and n different coin values c1 … cn, compute in how many ways
 *  it is possible to achieve change x by using each value at most twice. Here,
 *  two coins with the same value are considered equal.
 * ex: x = 4, c1 = 1, c2 = 2 => 1 + 1 +2, 2 + 2
 *
 * Assume 1 ≤ n ≤ 15, 1 ≤ ci ≤ x ≤ 106, and that all ci are different.
 * For every case print the number of different ways to achieve change exactly
 *  x by using each value at most twice.
 *
 * Hint: a simply pruned backtracking should be enough.
*/

#include <algorithm>
#include <iostream>
#include <vector>

// Prunings:
// 1. If sum > x, stop searching.

// i: position in solution vector
// j: position in candidates vector c 
// first: true if both values c[j] have never been visited
int combinations(int x, std::vector<int>& c, int sum, int j, bool first)
{
  if (sum == x) return 1;
  else if (sum < x and j < int(c.size())) {
    int s = 0;

    if (first) s += combinations(x, c, sum + c[j], j, false); // using c[j] one time (with possibility of using it another time)
    else s += combinations(x, c, sum + c[j], j+1, true); // using c[j] two times

    s += combinations(x, c, sum, j+1, true); // without using c[j]
    return s;
  }
  return 0;
}

int combinations(int x, std::vector<int>& c)
{
  return combinations(x, c, 0, 0, true);
}

int main()
{
  int x, n;
  while (std::cin >> x >> n) {
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) std::cin >> c[i];
    std::sort(c.begin(), c.end());

    std::cout << combinations(x, c) << std::endl;
  }
}
