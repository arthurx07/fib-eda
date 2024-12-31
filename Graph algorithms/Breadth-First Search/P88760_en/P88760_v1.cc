/* Lake of the Dragon God (Zamburguesas)
*/

#include <map>
#include <vector>
#include <iostream>
#include <cmath>
#include <queue>

struct node {
  int x, y, r;
};
// VER SERVIR: VECTOR (CONSULTAR ÉS CONSTANT, NO COM A MAP)
// !!!
using graph = std::map<node, std::vector<node*>>;

// 1. Leer el input como un grafo:
//    - por todas las rocas (n^2?): si dist(r1, r2) <= d, crear una arista (r1, r2)
//    - encontrar el camino mínimo de u (nodo 0) a v (nodo último) con un BFS.

int minimum_path(graph& G, node f, node l)
{
  std::queue<node> Q;
  std::map<node, int> dist; // (G.size());
  std::map<node, bool> enc; // (G.size());

  Q.push(f);
  dist[f] = 0;
  enc[f] = true;

  while (not Q.empty()) {
    node u = Q.front();
    Q.pop();

    if (u.x == l.x and u.y == l.y and u.r == l.r)
      return dist[u];
    
    for (const node *w : G[u]) {
      if (not enc[*w]) {
        Q.push(*w);
        enc[*w] = true;
        dist[*w] = dist[u] + 1;
      }
    }
  }
  return -1;
}

int main()
{
  graph G;
  int n, d;
  std::cin >> n >> d;

  node f;
  std::cin >> f.x >> f.y >> f.r;
  G[f];

  for (int i = 1; i < n-1; ++i) {
    node u;
    std::cin >> u.x >> u.y >> u.r;
    G[u];
  }

  node l;
  std::cin >> l.x >> l.y >> l.r;
  G[l];

  for (auto u : G) { // !!
    node u2 = u.first;
    for (auto w : G) { // !!
      node w2 = w.first;
      int c1 = abs(u2.x - w2.x); // ->first // .first
      int c2 = abs(u2.y - w2.y);
      int e = sqrt(c1*c1 + c2*c2) - u2.r - w2.r;
      if (e <= d) {
        G[u2].push_back(&w2);
        G[w2].push_back(&u2);
      }
    }
  }

  int min;
  if ((min = minimum_path(G, f, l)) > 0) std::cout << min << std::endl;
  else std::cout << "Xof!" << std::endl;
}
