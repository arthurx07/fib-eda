/* Forest
* A forest is a graph without cycles, and each of its connected components is a
* tree. Given an undirected graph, is it a forest? In case it is, how many trees
* does it have?
*/
#include <iostream>
#include <vector>

using graph = std::vector<std::vector<int>>; // adjacency list

// Returns true if the cc of the vertex u is a tree.
bool dfs_tree(const graph& G, int u, int p, std::vector<bool>& vis)
{
    if (not vis[u]) {
        vis[u] = true;
        for (int w : G[u]) {
            if (vis[w] and w != p) return false;
            if (not dfs_tree(G, w, u, vis)) return false;
        }
    }
    return true;
}

// Returns the number of cc in the graph, or -1 if the graph is not a tree.
int dfs_forest(graph& G)
{
    int c = 0;
    int n = G.size();
    std::vector<bool> vis(n, false);

    for (int u = 0; u < n; ++u) { // loop used to go search all cc.
        if (not vis[u]) {
            ++c;
            if (not dfs_tree(G, u, -1, vis)) return -1;
        }
    }

    return c;
}

int main()
{
    int n, m;
    while (std::cin >> n >> m) {
        graph G(n);
        int x, y;
        for (int i = 0; i < m; ++i) {
            std::cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        int count = dfs_forest(G);
        if (count > 0) std::cout << count << std::endl;
        else std::cout << "no" << std::endl;
    }
}
