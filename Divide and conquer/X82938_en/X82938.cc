/* In this problem, we say that a vector with n integer numbers v[0..n−1] is unimodal if n ≥ 1, and there exists an index j such that 0 ≤ j ≤ n−1 and satisfying:
     * v[0] < … < v[j−1] < v[j], and
     * v[j] > v[j+1] > v[j+2] > … > v[n−1]. 
   Note that vectors with n ≤ 2 different elements are unimodal. In general, note
    that any strictly increasing vector is also unimodal (and in all cases j = n−1),
    and analogously, any strictly decreasing vector is also unimodal (and then j = 0).
*/

#include <iostream>
#include <vector>

int unimodal_peak(const std::vector<int>& v, int i, int j)
{
  if (i == j) return i; // case one elements
  if (i+1 == j) // case two elements
  {
    if (v[i] > v[j]) return i;
    else return j;
  }

  int m = (i + j) / 2;
  if (v[m-1] < v[m] and v[m] > v[m+1]) return m;
  if (v[m] < v[m+1]) return unimodal_peak(v, m+1, j);
  return unimodal_peak(v, i, m-1); // if (v[m-1] > v[m])
}

bool binary_search(bool reverse, int x, const std::vector<int>& v, int i, int j)
{
  if (i > j) return false;
  int m = (i + j) / 2;
  if ((x < v[m] and not reverse) or (x > v[m] and reverse)) return binary_search(reverse, x, v, i, m - 1);
  if ((x > v[m] and not reverse) or (x < v[m] and reverse)) return binary_search(reverse, x, v, m+1, j);
  return true;
}

// given an integer number x and a unimodal vector v, returns true if x appears in v, and false otherwise.
// Precondition: The vector v is unimodal.
bool search(int x, const std::vector<int>& v)
{
  int peak = unimodal_peak(v, 0, v.size() - 1);
  if (x == v[peak]) return true;
  return binary_search(false, x, v, 0, peak) or binary_search(true, x, v, peak, v.size()-1);
}
