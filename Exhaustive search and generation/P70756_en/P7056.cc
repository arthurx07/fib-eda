/* Partitions
 * Write a program that, given n different words s1, …, sn and a number p,
 *  prints *all* the ways to share the words between p subsets.
 *  The elements of each set must appear in the same order than the input.
 * 
 * obs: Strictly speaking, a partition cannot have empty subsets, but we forget
 *  about that restriction in this exercise.
*/

#include <iostream>
#include <vector>

void print(std::vector<std::vector<std::string>>& A)
{
  for (int i = 0; i < int(A.size()); ++i) {
    std::cout << "subset " << i+1 << ": {";
    for (int j = 0; j < int(A[i].size()); ++j) {
      if (j > 0) std::cout << ',';
      std::cout << A[i][j];
    }
    std::cout << '}' << std::endl;
  }
  std::cout << std::endl;
}

void partitions(std::vector<std::vector<std::string>>& A, std::vector<std::string>& S,
                int i)
{
  if (i == int(S.size())) print(A);
  else {
    for (int j = 0; j < int(A.size()); ++j) {
      A[j].push_back(S[i]);
      partitions(A, S, i+1);
      A[j].pop_back();
    }
  }
}

void partitions(std::vector<std::string> S, int p)
{
  std::vector<std::vector<std::string>> A(p);
  partitions(A, S, 0);
}

int main()
{
  int n, p;
  std::cin >> n;

  std::vector<std::string> S(n);
  for (int i = 0; i < n; ++i) std::cin >> S[i];

  std::cin >> p;

  partitions(S, p);
}
