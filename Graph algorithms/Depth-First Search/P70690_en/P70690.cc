/* Treasures in a map (1)
* Write a program that, given a map with treasures and obstacles, tells if it is
* possible to reach some treasure from a given initial position. The allowed
* movements are horizontal or vertical, but not diagonal.
*/

#include <iostream>
#include <vector>

using map = std::vector< std::vector<char>>;
using matrixBool = std::vector< std::vector<bool>>;

bool dfs(const map& M, int i, int j, int n, int m, matrixBool& vis)
{
    if (i >= 0 and j >= 0 and i < n and j < m and not vis[i][j]) {
        vis[i][j] = true;
        if (M[i][j] == 'X') return false;
        // Any vertex only has 4 edges (up, down, left, right).
        return (M[i][j] == 't' or
                    dfs(M, i+1, j, n, m, vis) or
                    dfs(M, i-1, j, n, m, vis) or
                    dfs(M, i, j+1, n, m, vis) or
                    dfs(M, i, j-1, n, m, vis));
    }
    return false;
}

bool dfs(const map& M, int r, int c, int n, int m)
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

    dfs(M, r-1, c-1, n, m) ? std::cout << "yes" : std::cout << "no";
    std::cout << std::endl;
}
