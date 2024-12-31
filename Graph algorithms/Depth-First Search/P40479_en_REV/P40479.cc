/* Painting a board
* Write a program to paint several zones of an n × m board. Here, a zone is
* defined as a maximal set of adjoining cells, both horizontally and vertically.
*/

#include <iostream>
#include <vector>

using map = std::vector< std::vector<char>>;
using matrixBool = std::vector< std::vector<bool>>;

void fill_zones(map& M, int i, int j, int c, matrixBool& vis)
{
    if (i >= 0 and j >= 0 and i < int(M.size()) and j < int(M[0].size()) and
        not vis[i][j] and M[i][j] != '#') {

        vis[i][j] = true;
        M[i][j] = c;

        fill_zones(M, i+1, j, c, vis);
        fill_zones(M, i-1, j, c, vis);
        fill_zones(M, i, j+1, c, vis);
        fill_zones(M, i, j-1, c, vis);
    }
}

void fill_zones(map& M)
{
    int n = M.size();
    int m = M[0].size();
    matrixBool vis(n, std::vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // OPTIMIZACIÓN: MARCAR COMO VISITADO AQUÍ
            if (M[i][j] != '#' and M[i][j] != '.') fill_zones(M, i, j, M[i][j], vis);
        }
    }
}

int main()
{
    int n, m;
    while (std::cin >> n >> m) {
        map M(n, std::vector<char>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                std::cin >> M[i][j];

        fill_zones(M);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                std::cout << M[i][j];
            std::cout << std::endl;
        }

        std::cout << std::endl;
    }
}
