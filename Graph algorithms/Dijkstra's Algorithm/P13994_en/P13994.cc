/* Weighted shortest path (2)
* Write a program that, given a directed graph with positive costs at the arcs,
* and two vertices x and y, prints the path of minimum cost that goes from x to y.
*
* Input consists of several cases. Every case begins with the number of vertices
* n and the number of arcs m. Follow m triples u, v, c, indicating that there is
* an arc u → v of cost c, where u ≠ v and 1 ≤ c ≤ 10^4. Finally, we have x and y.
* Assume 1 ≤ n ≤ 10^4, 0 ≤ m ≤ 5n, and that for every pair of vertices u and v there
* is at most one arc of the kind u → v. All numbers are integers. Vertices are
* numbered from 0 to n−1. ¿¿If y is reachable from x, you have the guarantee that
* there is a unique path.??
*/

#include <iostream>
#include <vector>
#include <queue>

using arc = std::pair<int, int>; // pair (cost, vertex)
using graph = std::vector<std::vector<arc>>;

std::vector<int> dijkstra(graph& G, int x, int y)
{
  std::vector<int> prev(G.size(), -1);
  std::vector<int> dist(G.size(), -1);
  std::vector<bool> vis(G.size(), false);
  std::priority_queue<arc> H; // remember: in c++ it's a max_heap.
  // By default priority of the elements is dependent upon the first element
  // In this case, the cost.

  dist[x] = 0;
  H.push(arc(0, x));

  while (not H.empty())
  {
    int u = H.top().second;
    H.pop();

    if (not vis[u])
    {
      vis[u] = true;
      for (arc a : G[u])
      {
        int c = a.first;
        int v = a.second;
        if (dist[v] == -1 or dist[v] > dist[u] + c) {
          dist[v] = dist[u] + c;
          prev[v] = u;
          H.push( arc((-1)*dist[v], v) );
        }
      }
    }
  }

  if (dist[y] == -1) return std::vector<int>();

  std::vector<int> P;
  for (int i = y; i != x; i = prev[i])
    P.push_back(i);
  P.push_back(x);
  return P;
}

int main()
{
  int n, m;
  while (std::cin >> n >> m)
  {
    graph G(n);
    for (int i = 0; i < m; ++i) {
      int u, v, c;
      std::cin >> u >> v >> c;
      G[u].push_back(arc(c, v));
    }

    int x, y;
    std::cin >> x >> y;
    
    std::vector<int> P = dijkstra(G, x, y);

    if (P.empty()) std::cout << "no path from " << x << " to " << y << std::endl;
    else {
      for (int i = P.size()-1; i >= 0; --i) {
        std::cout << P[i];
        if (i != 0) std::cout << ' ';
      }
      std::cout << std::endl;
    }
  }
}
