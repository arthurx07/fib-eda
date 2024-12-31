/* Cost: 0((n+m)logn) */

typedef pair<double, int> arc;
typedef vector< vector<arc> > graph;

// Trobar el camí mínim d'un graf des de s a tots els vèrtex
void dijkstra (const graph& G, int s, vector<double>& d, vector<int>& p)
{
  int n = G.size();
  d = vector<double> (n, INF);
  p = vector<int> (n, -1);
  vector<bool> S(n, false);
  priority_queue<arc> Q; // max_heap. min_heap: priority_queue<arc, vector<arc>, greater<arc>> Q
  d[S] = 0;
  Q.push(arc(0, s));

  while (not Q.empty()) {
    int u = Q.top().second;
    Q.pop();
    if (not S[u]) {
      S[u] = true;
      for (int i = 0; i < int(G[u].size()); ++i) {
        int v = G[u][i].second;
        int c = G[u][i].first;
        if (d[v] > d[u] + c) {
          d[v] = d[u] + c;
          p[v] = u;
          Q.push( arc(-d[v], v) ); // if min_heap, remove the negative (-) sign
        }
      }
    }
  }
}
