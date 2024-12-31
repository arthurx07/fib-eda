/* Treasures in a map (2)
* Write a program that, given a map with treasures and obstacles, computes the
* distance from a given initial position to the nearest accessible treasure. The
* allowed movements are horizontal or vertical, but not diagonal.
*/

#include <iostream>
#include <vector>
#include <queue>

using map = std::vector< std::vector<char>>;
using matrixBool = std::vector< std::vector<bool>>;
using matrixInt = std::vector< std::vector<int>>;

// Returns minimum distance to a tresure. If no tresure is reached, returns -1
int bfs(const map& M, int r, int c, int n, int m)
{
  std::queue<std::pair<int, int>> Q;
  matrixInt dist(n, std::vector<int> (m, -1));
  matrixBool enc(n, std::vector<bool> (m, false));

  Q.push(std::make_pair(r, c));
  dist[r][c] = 0;
  enc[r][c] = true;

  while (not Q.empty()) {
    int i = Q.front().first, j = Q.front().second;
    Q.pop();
    
    if (M[i][j] == 't')
      return dist[i][j];

    if (i+1 >= 0 and j >= 0 and i+1 < n and j < m and not enc[i+1][j] and M[i+1][j] != 'X') {
      Q.push(std::make_pair(i+1, j));
      enc[i+1][j] = true;
      dist[i+1][j] = dist[i][j] + 1;
    }
    if (i-1 >= 0 and j >= 0 and i-1 < n and j < m and not enc[i-1][j] and M[i-1][j] != 'X') {
      Q.push(std::make_pair(i-1, j));
      enc[i-1][j] = true;
      dist[i-1][j] = dist[i][j] + 1;
    }
    if (i >= 0 and j+1 >= 0 and i < n and j+1 < m and not enc[i][j+1] and M[i][j+1] != 'X') {
      Q.push(std::make_pair(i, j+1));
      enc[i][j+1] = true;
      dist[i][j+1] = dist[i][j] + 1;
    }
    if (i >= 0 and j-1 >= 0 and i < n and j-1 < m and not enc[i][j-1] and M[i][j-1] != 'X') {
      Q.push(std::make_pair(i, j-1));
      enc[i][j-1] = true;
      dist[i][j-1] = dist[i][j] + 1;
    }
  }
  return -1;
}

int main()
{
  int n, m, r, c;
  std::cin >> n >> m;
  map M(n, std::vector<char> (m));

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      std::cin >> M[i][j];
  std::cin >> r >> c;

  int min;
  if ((min = bfs(M, r-1, c-1, n, m)) > 0) std::cout << "minimum distance: " << min << std::endl;
  else std::cout << "no treasure can be reached" << std::endl;
}
