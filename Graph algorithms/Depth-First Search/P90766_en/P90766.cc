/* Treasures in a map (3)
* Write a program that, given a map with treasures and obstacles, computes the
* number of treasures that can be reached from a given initial position. The
* allowed movements are horizontal or vertical, but not diagonal. If needed,
* passing over the treasures is allowed.
*/

#include <iostream>
#include <vector>

using map = std::vector< std::vector<char>>;
using matrixBool = std::vector< std::vector<bool>>;

int dfs(const map& M, int i, int j, int n, int m, matrixBool& vis)
{
    if (i >= 0 and j >= 0 and i < n and j < m and not vis[i][j]) {
        vis[i][j] = true;
        if (M[i][j] == 'X') return 0;

        int c = (M[i][j] == 't') ? 1 : 0;
        // Any vertex only has 4 edges (up, down, left, right).
        return (c +
                dfs(M, i+1, j, n, m, vis) +
                dfs(M, i-1, j, n, m, vis) +
                dfs(M, i, j+1, n, m, vis) +
                dfs(M, i, j-1, n, m, vis));
    }
    return 0;
}

int dfs(const map& M, int r, int c, int n, int m)
{
    matrixBool vis(n, std::vector<bool> (m, false));
    return dfs(M, r, c, n, m, vis);
}

int main() {
    int n, m, r, c;
    std::cin >> n >> m;
    map M(n, std::vector<char> (m));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> M[i][j];
    std::cin >> r >> c;

    std::cout << dfs(M, r-1, c-1, n, m) << std::endl;
}
