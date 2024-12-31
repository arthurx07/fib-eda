/* Minimum spanning trees
 * Given a connected, undirected graph, a spanning tree of that graph is a subgraph
 * which is a tree and connects all the vertices together. On a weighted graph,
 * the weight of a spanning tree is the sum of the weights of its edges. A minimum
 * spanning tree is a spanning tree with weight less than or equal to the weight
 * of every other spanning tree.
 *
 * There are no edges connecting a vertex to itself, but there may be more than
 * two edges connecting the same pair of vertices. Every given graph is connected.
 * All weights are strictly positive integers.
*/

#include <iostream>
#include <vector>
#include <queue>

using arc = std::pair<int, int>; // pair (cost, vertex)
using graph = std::vector<std::vector<arc>>;

// Returns the cost of an MST
int mst_prim(const graph& G)
{
  int n = G.size();
  std::vector<bool> vis(n, false); // Tall: vèrtexs no visitats vs vèrtex visitats
  std::priority_queue<arc, std::vector<arc>, std::greater<arc>> H; // remember: c++ uses max_heap by default

  vis[0] = true; // Al principi, únic element del tall: 0
  for (arc u : G[0]) // Arestes que creuen el tall (van d'un vèrtex visitat a un no visitat)
    H.push(u); // Afegeix e a A (com que A respecta el tall, això no pot crear un cicle)

  int cost = 0;
  for (int size = 1; size < n;) // Mentre l'Arbre no té el mateix nombre de vèrtexs que el tall
  {
    int c = H.top().first; // Aresta de pes mínim entre les que creuen el tall
    int v = H.top().second;
    H.pop();

    if (not vis[v]) {
      vis[v] = true;
      for (arc w : G[v]) // Arestes que creuen el tall (van d'un vèrtex visitat a un no visitat)
        H.push(w); // Afegeix e a A (com que A respecta el tall, això no pot crear un cicle)

      cost += c; // S'afegeix el cost de l'aresta al cost totall
      ++size; // incrementem el nombre de vèrtexs de l'Arbre
    }
  }
  return cost;
}

int main()
{
  int n, m;
  while (std::cin >> n >> m)
  {
    graph G(n);

    for (int i = 0; i < m; ++i)
    {
      int u, v, w;
      std::cin >> u >> v >> w;
      G[u-1].push_back(arc(w, v-1));
      G[v-1].push_back(arc(w, u-1));
    }

    std::cout << mst_prim(G) << std::endl;
  }
}
