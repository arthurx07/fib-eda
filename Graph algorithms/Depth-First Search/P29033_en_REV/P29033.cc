/* Two colors
* Write a program that, given an undirected graph, tells if we can paint all
* vertices with only two colors, in such a way that no two neighboring vertices
* have the same color.
*
* Suppose 1 ≤ n ≤ 104, 0 ≤ m ≤ 5n, that vertices are numbered from 0 to n − 1,
* x ≠ y, and that there is no more than one edge between any pair x y.
*/

#include <iostream>
#include <vector>
#include <stack>

using graph = std::vector<std::vector<int>>; // adjacency list

/*
// Returns true if a cycle of odd size is found.
bool odd_cycles(const graph& G, int u, int p, std::vector<bool>& vis, std::vector<bool>& fin)
{
  if (fin[u]) return false;
  if (vis[u]) return true;

  vis[u] = true;

  for (int w : G[u])
    if (w != p and odd_cycles(G, w, u, vis, fin)) return true;

  fin[u] = true;
  return false;
}

// Returns true if a cycle of odd size is found.
bool odd_cycles(graph& G)
{
  int n = G.size();
  std::vector<bool> vis(n, false);
  std::vector<bool> fin(n, false);

  for (int u = 0; u < n; ++u) { // loop used to go search all cc.
    if (odd_cycles(G, u, -1, vis, fin)) return true;
  }

  return false;
}
*/

bool two_colorable(graph& G)
{
  int n = G.size();
  std::stack<int> S;
  std::vector<bool> vis(n, false);
  std::vector<int> color(n, false);
  // We set color to 0, and then we paint the 1 ones. If one to which 0 is
  //  corresponded at one point needs a 1 (or the reverse), the graph is not
  //  2-colorable.

  for (int u = 0; u < n; ++u) // ccs
  {
    if (not vis[u])
    {
      S.push(u);
      color[u] = false;
      while (not S.empty()) {
        int v = S.top();
        S.pop();
        vis[v] = true;
        for (int w : G[v]) {
          if (not vis[w]) {
            S.push(w);
            color[w] = (not color[v]);
          }
          else if (color[w] == color[v]) return false;
        }
      }
    }
  }
  return true;
}

int main()
{
  int n, m;
  while (std::cin >> n >> m)
  {
    graph G(n);
    int x, y;
    for (int i = 0; i < m; ++i) {
      std::cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }

    if (two_colorable(G)) std::cout << "yes" << std::endl;
    else std::cout << "no" << std::endl;
  }
}
