#include <vector>

/*  Θ(n) <= Tins(n) <= Θ(n^2), aquest algorisme és sensible a l'entrada. El seu
    cost canvia depenent d'aquesta. */
void insertion_sort (vector<int>& v, int n)
{
  for (int k = 1; k <= n-1; ++k)
  {
    int t = k - 1;
    while (t >= 0 and v[t+1] < v[t])
    {
      std::swap(v[t], v[t+1]);
      --t;
    }
  }
}
