/* Cost en cas pitjor: 0(mlogn) */

typedef pair<double, int> arc;
typedef vector< vector<arc> > graph;

/* El graf està representat amb llistes d'adjacència. Els parells són (cost, vèrtex)
 * Retorna el cost d'un MST */
int mst_prim(const graph& G) {
  int n = G.size();
  vector<bool> vis(n, false);
  vis[0] = true;
  priority_queue<arc, vector<arc>, greater<arc>> pq;

  for (arc x : g[0])
    pq.push(x);

  int size = 1;
  int sum = 0;
  while (size < n) {
    int c = pq.top().first;
    int x = pq.top().second;
    pq.pop();
    if (not vis[x]) {
      vis[x] = true;
      for (arc y : g[x])
        pq.push[y];
      sum += c;
      ++size;
    }
  }
  return sum;
}
