/* Tiny bishops
* Consider an n × m chess board, where some cells are legal and some are prohibited.
* You have many small bishops, so tiny that an unbounded number of them fit in
* every cell. As expected, bishops can only move diagonally. For every given board
* description, tell if there is a way to (repeatedly) move as many bishops as
* needed, never passing a prohibited cell, so that eventually all the legal cells
* have the same number of bishops.
*
* Prohibited cells are marked with an 'x'. No cell has more than 1000 bishops.
*/

#include <iostream>
#include <vector>

using map = std::vector< std::vector<int>>;
using matrixBool = std::vector< std::vector<bool>>;

std::pair<int, int> ratio(const map& M, int i, int j, int n, int m, matrixBool& vis)
{
    if (i >= 0 and j >= 0 and i < n and j < m and not vis[i][j]) {
        vis[i][j] = true;
        if (M[i][j] == -1) return std::make_pair(0, 0);

        // Any vertex only has 4 edges (upper left, upper right, lower left, lower right).
        auto r1 = ratio(M, i+1, j+1, n, m, vis);
        auto r2 = ratio(M, i+1, j-1, n, m, vis);
        auto r3 = ratio(M, i-1, j+1, n, m, vis);
        auto r4 = ratio(M, i-1, j-1, n, m, vis);

        return std::make_pair(M[i][j] + r1.first + r2.first + r3.first + r4.first,
                              1 + r1.second + r2.second + r3.second + r4.second);
    }
    return std::make_pair(0, 0);
}

bool same_bishops(const map& M, int n, int m)
{
    double r = -1;

    matrixBool vis(n, std::vector<bool> (m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (M[i][j] != 'X' and not vis[i][j]) {
                std::pair<int, int> p = ratio(M, i, j, n, m, vis);
                double s = -1;
                if (p.second != 0) s = double(p.first)/p.second;
                // std::cout << i <<' '<< j<<' '<<p.first<<' '<<p.second<<' '<<s<<std::endl;

                if (s != -1) {
                    if (r == -1) r = s; // first iteration only
                    if (int(r) != r or r != s) return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    int t;
    std::cin >> t;
    for (int s = 1; s <= t; ++s)
    {
        int n, m;
        std::cin >> n >> m;

        map M(n, std::vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::string x;
                std::cin >> x;
                if (x == "X") M[i][j] = -1;
                else M[i][j] = stoi(x);
            }
        }

        std::cout << "Case " << s << ": ";
        if (same_bishops(M, n, m)) std::cout << "yes" << std::endl;
        else std::cout << "no" << std::endl;
    }
}
