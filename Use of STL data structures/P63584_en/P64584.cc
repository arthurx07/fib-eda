/* implement a function
 *    int k_esim(int k, const vector<vector<int>>& V);
 * to return the k-th global element (starting at one) of the elements in the
 * vector of vectors V. Let n = V.size(). For every 0 ≤ i < n, V[i] is sorted
 * increasingly. Furthermore, there are no repeated elements in V.
 *
 * Let m = ∑0n−1 V[i].size(). Assume that k is between 1 and m, that n is between
 * 2 and 500, and that some V[i] can be empty. If needed, you can implement auxiliar
 * procedures. Take into account that, for the “large” test cases, k = Θ(n) and
 * m = Θ(n2). The expected solution in this cas has cost Θ(n logn).
*/

#include <iostream>
#include <vector>
#include <map>

int k_esim(int k, const std::vector<std::vector<int> >& V)
{
  std::map<int, int> m; // conté els elements mínims de cada vector
  for (int i = 0; i < V.size(); ++i)
  {
    if (not V[i].empty()) m[ V[i][0] ] = i;
  }
  int min, i_min;
  // min: conté el valor mínim de la matriu
  // i_min: conté l'índex de la fila del valor mínim de la matriu

  std::vector<int> indexes(V.size(), 1); // conté l'índex de l'element mínim del vector amb possibilitat de ser k

  for (; k > 0; --k)
  {
    min = m.begin()->first;
    i_min = m.begin()->second;
    if (indexes[i_min] < V[i_min].size()) // si encara no s'ha arribat al final de la fila (vector)
    {
      m[ V[i_min][ indexes[i_min]++ ] ] = i_min;
      // el valor mínim de la fila i_min ara es m[...]
      // post incremento l'índex d'aquesta fila en un
    }
    m.erase(m.begin()); // esborro del map
  }
  return min;
}
