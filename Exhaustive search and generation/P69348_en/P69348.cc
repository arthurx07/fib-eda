/* From one to en (1)
 * Write program that prints all the permutations of {1, ..., n} in lexicographical
 *  order for a given natural number n > 0.
*/

#include <iostream>
#include <vector>

void print(std::vector<int>& V)
{
  std::cout << '(';
  for (int i = 0; i < int(V.size()); ++i) {
    if (i > 0) std::cout << ',';
    std::cout << V[i];
  }
  std::cout << ')' << std::endl;
}

// Prunes:
// Given a partial permutation A[0...i-1] the candidates for the position i
//  are the elements of {1,...,n} not presents in A.

void permutations(std::vector<int>& A, int i, std::vector<bool>& used)
{
  if (i == int(A.size())) print(A);
  else {
    for (int k = 1; k <= int(A.size()); ++k) {
      if (not used[k]) {
        A[i] = k;
        used[k] = true;
        permutations(A, i+1, used);
        used[k] = false; // restore under backtrack (as the next elements in for loop won't have used k)
      }
    }
  }
}

void permutations(int n)
{
  std::vector<int> A(n);
  std::vector<bool> used(n+1, false); // postion used[0] is unused.
  permutations(A, 0, used);
}

int main()
{
  int n;
  std::cin >> n;

  permutations(n);
}
