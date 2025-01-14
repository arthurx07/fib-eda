// Given an undirected graph, compute the number of vertices of the smallest and largest connected component.

// Input: number of vertices n, number of edges m. Followed by m pairs x y. Vertices are numbered from 0 to n-1. 1 <= n <= 10^4, 0 <= m <= 5n
// Ouput: For each graph, write the minimum and maximum size of its connected components.

#include <iostream>
#include <vector>
using namespace std;

using Graph = vector<vector<int>>; // Adjacency list graph representation

// Returns the size of the connected component of u.
int dfs(int u, Graph &G, vector<bool> &vis)
{
  if (not vis[u]) {
    int s = 1;
    vis[u] = true;
    for (int v : G[u]) {
      s += dfs(v, G, vis);
    }
    return s;
  }
  return 0;
}

// Returns a pair<int, int> which are the {minimum, maximum} of all the sizes of G's connected components.
pair<int,int> cc_min_max(Graph &G)
{
  int n = G.size();
  pair<int, int> cc = {-1, -1};
  vector<bool> vis(n, false);

  for (int u = 0; u < n; ++u) {
    if (not vis[u]) {
      int s = dfs(u, G, vis);
      if (s < cc.first or cc.first == -1) cc.first = s;
      if (s > cc.second) cc.second = s;
    }
  }
  return cc;
}

int main()
{
  int n, m;
  while (cin >> n >> m) {
    Graph G(n);
    for (int i = 0; i < m; ++i)
    {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }

    pair<int, int> cc = cc_min_max(G);
    cout << cc.first << ' ' << cc.second << endl;
  }
}
