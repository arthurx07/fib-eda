/* Permutations of words
 * Write a program that, given a number n>0 of differrent words s1, ..., sn, prints
 *  all the permutations that can be made up with the words.
 * info: you can print the solutions to this exercise in any order.
*/

#include <iostream>
#include <vector>

void print(std::vector<std::string>& V, std::vector<int> indexes)
{
  std::cout << '(';
  for (int i = 0; i < int(V.size()); ++i) {
    if (i > 0) std::cout << ',';
    std::cout << V[indexes[i]];
  }
  std::cout << ')' << std::endl;
}

// Prunes:
// Given a partial permutation A[0...i-1] the candidates for the position i
//  are the elements of (s1,..,sn) with their index in V not present in A.

void permutations(std::vector<std::string>& V, std::vector<int>& A, int i,
                  std::vector<bool>& used)
{
  if (i == int(A.size())) print(V, A);
  else {
    for (int k = 0; k < int(V.size()); ++k) {
      if (not used[k]) {
        A[i] = k;
        used[k] = true;
        permutations(V, A, i+1, used);
        used[k] = false; // restore under backtrack (as the next elements in for loop won't have used index k)
      }
    }
  }
}

void permutations(std::vector<std::string>& V)
{
  std::vector<int> A(int(V.size())); // current permutation, with the indexes of the words in V
  std::vector<bool> used(int(V.size()), false);

  permutations(V, A, 0, used);
}

int main()
{
  int n;
  std::cin >> n;

  std::vector<std::string> V(n);
  for (int i = 0; i < n; ++i)
    std::cin >> V[i];

  permutations(V);
}
