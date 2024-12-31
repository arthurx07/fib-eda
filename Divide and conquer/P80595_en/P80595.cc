/* Count the number of inversions of every given sequence of n integer numbers
 *  x1 … xn. Remember that an inversion is a pair of indices i and j such that 
 *  1 ≤ i < j ≤ n and xi > xj.
 */

#include <iostream>
#include <vector>

void merge(std::vector<int>& M, int l, int m, int r, int& count)
{
  std::vector<int> V(r-l+1);
  int i = l, j = m+1, k = 0;

  while (i <= m and j <= r)
  {
    if (M[i] <= M[j]) V[k++] = M[i++];
    else
    {
      count += (m+1) - i;
      V[k++] = M[j++];
    }
  }

  while (i <= m) V[k++] = M[i++];
  while (j <= r) V[k++] = M[j++];
  for (k = 0; k <= r-l; ++k) M[l+k] = V[k];
}

void mergesort(std::vector<int>& M, int l, int r, int& count)
{
  if (l < r)
  {
    int m = (l+r)/2;
    mergesort(M, l, m, count);
    mergesort(M, m + 1, r, count);
    merge(M, l, m, r, count);
  }
}

int count_inversions(std::vector<int> v)
{
  int c = 0;
  mergesort(v, 0, v.size() - 1, c);
  return c;
}

int main()
{
  int n;
  while (std::cin >> n)
  {
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) std::cin >> v[i];

    std::cout << count_inversions(v) << std::endl;
  }
}
