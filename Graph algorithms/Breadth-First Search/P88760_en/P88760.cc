/* Lake of the Dragon God (Zamburguesas)
 * The Lake of the Dragon God is one of the most mythical challenges of the contest.
 * A river must be crossed by jumping from rock to rock, but be careful! Some
 * rocks are fake and sink!
 * There are n true rocks, all round, with centre (xi, yi) and radius ri. The maximum
 * distance that a contestant can jump is d (measuring it from the border of the
 * rocks). Your task is to compute the minimum number of jumps to go from the
 * first rock to the last one without falling into the water. If it is impossible,
 * state so.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

struct node {
  double x, y, r;
};

using graph = std::vector<std::vector<int>>;

// Leer el input como un grafo:
//  - para todas las rocas (n): si dist(r1, r2) <= d, crear una arista (r1, r2)
//  - encontrar el camino mínimo de u (nodo 0) a v (nodo último) con un BFS.

// BFS on graph
int minimum_path(graph& G, int s, int v)
{
  std::queue<int> Q;
  std::vector<int> dist(G.size(), -1);
  std::vector<bool> enc(G.size(), false);

  Q.push(s);
  dist[s] = 0;
  enc[s] = true;

  while (not Q.empty()) {
    int u = Q.front();
    Q.pop();

    if (u == v)
      return dist[u];
    
    for (int w : G[u]) {
      if (not enc[w]) {
        Q.push(w);
        enc[w] = true;
        dist[w] = dist[u] + 1;
      }
    }
  }
  return -1;
}

// pithagora's theorem
double distance(node u, node v)
{
  double c1 = u.x - v.x;
  double c2 = u.y - v.y;
  return sqrt(c1*c1 + c2*c2) - u.r - v.r;
}

int main()
{
  int n;
  double d;
  while (std::cin >> n >> d)
  {
    std::vector<node> V(n);
    for (int i = 0; i < n; ++i) {
      node u;
      std::cin >> u.x >> u.y >> u.r;
      V[i] = u;
    }

    graph G(n);
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        if (distance(V[i], V[j]) <= d) {
          G[i].push_back(j);
          G[j].push_back(i);
        }
      }
    }

    int min;
    (min = minimum_path(G, 0, n-1)) > 0 ? std::cout << min << std::endl
                                        : std::cout << "Xof!" << std::endl;
  }
}
