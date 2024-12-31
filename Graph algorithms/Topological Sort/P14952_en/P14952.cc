/* Topological sort
* We must perform n tasks, one at a time. Furthermore, some tasks must be done
* before others: there are m precedence relations between tasks. Write a program
* to print a way to sort the n tasks satisfying the m given precedences.
*
* Every case begins with n, followed by m, followed by m distinct pairs x y that
* indicate that task x must be done before task y. You can assume 1 ≤ n ≤ 104,
* 0 ≤ m ≤ 10n, and that the tasks are numbered from 0 to n − 1.
*
* For every case, print the lexicographically smallest order of the n tasks that
* fulfills the m given precedences. There will always be, at least, one solution.
*/

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using node = int;
using graph = std::vector<std::vector<node>>;

std::list<int> topological_sort(const graph& G)
{
  int n = G.size();
  std::vector<int> edges(n, 0);
  for (int u = 0; u < n; ++u)
    for (int w : G[u]) ++edges[w];

  std::priority_queue<int> Q; // min_heap: std::priority_queue<int, std::vector<int>, std::greater<int>>;
  for (int u = 0; u < n; ++u) // C++ implements a max_heap, trick: append a negative sign to the value
    if (not edges[u]) Q.push(-u);

  std::list<int> L;
  while (not Q.empty()) {
    int u = (-1)*Q.top();
    Q.pop();
    L.push_back(u);

    for (int w : G[u])
      if (not --edges[w]) Q.push(-w);
  }
  return L;
}

int main()
{
  int n, m;
  while (std::cin >> n >> m)
  {
    graph T(n);
    for (int i = 0; i < m; ++i) {
      int x, y;
      std::cin >> x >> y;
      T[x].push_back(y);
    }

    std::list<int> L = topological_sort(T);

    for (std::list<int>::iterator it = L.begin(); it != L.end(); ++it) {
      std::cout << *it;
      if (it != --L.end()) std::cout << ' ';
    }
    std::cout << std::endl;
  }
}
