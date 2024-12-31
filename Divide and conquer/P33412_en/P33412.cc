/* Write an efficient function
*    bool resistant_search(double x, const vector<double>& v);
*  that tells if x belongs to the vector v or not.
*
*  Precondition
*    The vector v is “almost sorted” in nondecreasing order, in the sense that
*    there may be at most a pair of indices i and j such that 0 ≤ i < j < n and V[i] > V[j].
*/

#include <iostream>
#include <vector>

bool binary_search(double x, const std::vector<double>& v, int l, int r)
{
  if (l > r) return false;
  int m = (l + r)/2;

  /* Option 1
  if ((m > l and x == v[m-1]) or (m < r and x == v[m+1])) return true;
  else if (x < v[m]) return binary_search(x, v, l, m-2);
  else if (x > v[m]) return binary_search(x, v, m+2, r); */

  /* Option 2 */
  if (x < v[m] and (m == r or x != v[m+1])) return binary_search(x, v, l, m-1);
  else if (x > v[m] and (m == l or x != v[m-1])) return binary_search(x, v, m+1, r);

  return true;
}

bool resistant_search(double x, const std::vector<double>& v)
{
  return binary_search(x, v, 0, v.size() - 1);
}

int main() {
  int n;
  while (std::cin >> n) {
    std::vector<double> V(n);
    for (int i = 0; i < n; ++i) std::cin >> V[i];

    int t;
    std::cin >> t;
    while (t--) {
      double x;
      std::cin >> x;
      std::cout << resistant_search(x, V) << std::endl;
    }
  }
}
