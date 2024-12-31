/* Cost: 0(n + m), usant llistes d'adjacència */

list<int> bfs(const graph& G)
{
  int n = Q.size();
  list<int> L;
  queue<int> Q;
  vector<bool> enc(n, false);

  for (int u = 0; u < n; ++u) {
    if (not enc[u]) {
      Q.push(u);
      enc[u] = true;
      /* marcar-los com a encuats (visitats) en el moment de posar-los a la cua
         [sinó és molt ineficient en termes de memòria] */
      while(not Q.empty()) {
        int v = Q.front();
        Q.pop();
        L.push_back(v);
        for (int w : G[v]) {
          if (not enc[w]) {
            Q.push(w);
            enc[w] = true;
          }
        }
      }
    }
  }
  return L;
}
