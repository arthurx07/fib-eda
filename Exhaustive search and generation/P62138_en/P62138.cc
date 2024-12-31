/* Topological orderings
 * There are n tasks, which have to be done one by one. Some tasks must be done
 *  before others: there are m precedence relations between tasks. Write a program
 *  that prints all possible ways to order the n tasks according to the m given
 *  precedences.
 *
 * Input: natural number n>=1, natural number m, m different pairs x,y. Indicating
 *  that task x must be done before task y. Tasks are numbered from 0 to n-1.
 *
 * Output: Print, one per line and in lexicographic order, all the ways of sorting
 *  the n tasks according to the m given precedences. There will always be at least
 *  one solution.
*/

#include <iostream>
#include <map>
#include <vector>

void print(std::vector<int>& A)
{
  for (int i = 0; i < int(A.size()); ++i) {
    if (i > 0) std::cout << ' ';
    std::cout << A[i];
  }
  std::cout << std::endl;
}

void orderings(std::vector<int>& A, std::map<int, std::vector<int>>& P, std::vector<int>& use, int i)
{
  if (i == int(A.size())) print(A);
  else {
    for (int k = 0; k < int(A.size()); ++k) {
      if (use[k] == 0) {
        A[i] = k;

        ++use[k];
        if (P.count(k)) {
          for (int y : P[k]) --use[y];
        }

        orderings(A, P, use, i+1);

        --use[k];
        if (P.count(k)) {
          for (int y : P[k]) ++use[y];
        }
      }
    }
  }
}

int main()
{
  int n, m;
  std::cin >> n >> m;

  std::vector<int> use(n, 0); // true if use[i] can be used
  std::map<int, std::vector<int>> P; // x -> y (x has to be done before y)
  for (int i = 0; i < m; ++i) {
    int x, y;
    std::cin >> x >> y;
    P[x].push_back(y);
    ++use[y];
  }

  std::vector<int> A(n);
  orderings(A, P, use, 0);
}

// To Do: Not using a map?
