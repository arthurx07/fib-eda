#include <iostream>
#include <vector>
#include <map>

/* return the k-th global element (starting at one) of the elements in the vector
of vectors V. Let n = V.size(). For every 0 ≤ i < n, V[i] is sorted increasingly.
Furthermore, there are no repeated elements in V. */
int k_esim(int k, const std::vector<std::vector<int> >& V)
{
  std::map<int, std::pair<int, int>> m; // ordered: (elem) = [i][j]
  for (int i = 0; i < V.size(); ++i)
    if (not V[i].empty()) m[ V[i][0] ] = std::make_pair(i, 0);

  int min, i, j;
  for (; k > 0; --k) // k starts at 1
  {
    min = m.begin()->first;
    i = m.begin()->second.first;
    j = m.begin()->second.second;
    if (j < V[i].size()) // si encara no s'ha arribat al final de la fila (vector)
    {
      m[ V[i][j++] ] = std::make_pair(i, j);
    }
    m.erase(m.begin()); // esborro del map
  }
  return min;
}
