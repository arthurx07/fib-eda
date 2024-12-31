/* Cost: 0(n+m) */

/* VERSIÓ RECURSIVA */

// Visitar tots els vèrtex possibles a partir d'un vèrtex u donat.
void dfs_rec(const graph& G, int u, vector<bool>& vis, list<int>& L)
{
  if (not vis[u]) {
    vis[u] = true;
    L.push_back(u);
    for (int w : G[u])
      dfs_rec(G, w, vis, L);
  }
}

std::list<int> dfs_rec(const graph& G)
{
  int n = G.size();
  list<int> L;
  vector<bool> vis(n, false);
  for (int u = 0; u < n; ++u)
    dfs_rec(G, u, vis, L);
  return L;
}

/* VERSIÓ ITERATIVA */

list<int> dfs_it(const graph& G)
{
  int n = G.size();
  list<int> L;
  stack<int> S;
  vector<bool> vis(n, false);

  for (int u = 0; u < n; ++u) {
    S.push(u);
    while (not S.empty()) {
      int v = S.top();
      S.pop;
      if (not vis[v]) {
        vis[v] = true;
        L.push_back(v);
        for (int w : G[w]) S.push(w);
      }
    }
  }
  return L;
}
