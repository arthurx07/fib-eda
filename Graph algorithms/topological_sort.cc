/* Cost: 0(n+m), amb llistes d'adjacència */

list<int> topological_sort(graph& G)
{
  int n = G.size();
  vector<int> ge(n, 0);
  for (int u = 0; u < n; ++u)
    for (int i = 0; i < G[u].size(); ++i)
      ++ge[ G[u][i] ];

  stack<int> S;
  for (int u = 0; u < n; ++u)
    if (ge[u] == 0) S.push(u);

  list<int> L;
  while (not S.empty()) {
    int u = S.top();
    S.pop();
    L.push_back(u);
    for (int i = 0; i < G[u].size(); ++i) {
      int v = G[u][i];
      if (--ge[v] == 0) S.push(v);
    }
  }
  return L;
}
