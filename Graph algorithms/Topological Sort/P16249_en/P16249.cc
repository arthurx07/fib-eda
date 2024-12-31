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
#include <queue>
#include <map>

using node = std::string;
using graph = std::map<std::string, std::vector<node>>;

std::list<std::string> topological_sort(graph& G)
{
  std::map<std::string, int> edges;
  for (auto u : G)
    for (std::string w : G[u.first]) ++edges[w];

  std::priority_queue<std::string, std::vector<std::string>,
                      std::greater<std::string>> Q; // min_heap
  for (auto u : G)
    if (not edges[u.first]) Q.push(u.first);

  std::list<std::string> L;
  while (not Q.empty()) {
    std::string u = Q.top();
    Q.pop();
    L.push_back(u);

    for (std::string w : G[u])
      if (not --edges[w]) Q.push(w);
  }
  return L;
  // Note:
  //  - L.size() == G.size(), it means we have sorted all elements.
  //  - Otherwise, it means there's no topological order, and there'll be
  //    some vertice which (edges[w] != 0) is true at the end of the procedure.
}

int main()
{
  int n;
  while (std::cin >> n)
  {
    graph T;
    for (int i = 0; i < n; ++i) {
      std::string s;
      std::cin >> s;
      T[s];
    }

    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
      std::string s, t;
      std::cin >> s >> t;
      T[s].push_back(t);
    }

    std::list<std::string> L = topological_sort(T);

    if (L.size() == T.size()) {
      for (std::string s : L)
        std::cout << s;
    }
    else std::cout << "NO VALID ORDERING";
    std::cout << std::endl;
  }
}
