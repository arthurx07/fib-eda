/* Incompatible Species
 * Consider n different species. Some may be incompatible, in the sense that they
 *  must be kept separated. For example, if the species were human, lion, gorilla,
 *  buffalo and antelope, then the list of incompatibilities might be: we cannot
 *  put a human next to a lion, nor a human next to a buffalo, nor a lion next to
 *  a buffalo, nor a lion next to a antelope.

 * Write a program that reads the incompatibilities between species, and writes
 *  all the ways to put in a row an individual of every species, so that two
 *  incompatible species are never one beside the other.
 *
 * Input: 1 <= n <= 52, followed by n letters each identifying a different species.
 *  number m, followed by m different pairs of letters, each indicating an incompatibility
 *  between two of the n given speciees.
 *
 * Output: Print all the ways of placing n individuals in a row, one of each species,
 *  so that incompatible species are not together.
 *
 * Info: You can print the solutions to this exercise in any order.
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>

void print(std::vector<char> A)
{
  for (char c : A) std::cout << c;
  std::cout << std::endl;
}

void rows(std::vector<char>& A, std::vector<char>& S, std::vector<std::vector<bool>>& I,
          std::vector<bool>& used, std::vector<bool>& blocked, int i)
{
  if (i == int(A.size())) print(A);
  else {
    for (int j = 0; j < int(S.size()); ++j) {
      if (not used[j] and not blocked[j]) {
        A[i] = S[j];
        used[j] = true;

        std::vector<bool> next_blocked(S.size());
        // We create a new blocked vector, as just after calling rows() the backtracking
        //  needs to be restored as how it was before doing this iteration.
        for (int k = 0; k < int(I[j].size()); ++k) 
          next_blocked[k] = I[j][k];

        rows(A, S, I, used, next_blocked, i+1);

        used[j] = false;
      }
    }
  }
}

void rows(std::vector<char>& S, std::vector<std::vector<bool>>& I)
{
  std::vector<char> A(S.size());
  std::vector<bool> used(S.size());
  std::vector<bool> blocked(S.size());
  rows(A, S, I, used, blocked, 0);
}

int main()
{
  int n, m;
  std::cin >> n;
  std::vector<char> S(n);
  std::map<char, int> mp;
  for (int i = 0; i < n; ++i) {
    std::cin >> S[i];
    mp[S[i]] = i;
  }

  std::cin >> m;
  std::vector<std::vector<bool>> I(n, std::vector<bool>(n, false));
  for (int i = 0; i < m; ++i) {
    char a, b;
    std::cin >> a >> b;
    int x = mp[a];
    int y = mp[b];
    I[x][y] = I[y][x] = true;
  }

  mp.clear(); // not needed

  rows(S, I);
}
