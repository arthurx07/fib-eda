#include <vector>

/* T(n) = Θ(n) */
int max_position (const vector<int>& v, int m)
{
  int k = 0;
  for (int i = 1; i <= m; ++i)
    if (v[i] > v[k]) k = i;
  return k;
}

/* Tsel(n) = Θ(n^2) */
void selection_sort (vector<int>& v, int n)
{
  for (int i = n-1; i >= 0; --i)
  {
    int k = max_position(v, i);
    std::swap(v[k], v[i]);
  }
}
