/* Consonants and vowels
 * Write a program that reads n consonants and n vowels given in alphabetical
 *  order, and prints alphabetically all the words that can be made up by using
 *  each letter exactly once. The words must begin with a consonant, and alternate
 *  consonants and vowels. In this exercise, we will assume that ‘y’ is a vowel.
 * 1 <= n <= 6
*/

#include <iostream>
#include <vector>

void print(std::vector<char>& S)
{
  for (char i : S) std::cout << i;
  std::cout << std::endl;
}

// Prunings:
//  If the consontant/vowel has already been used, do not continue the subtree.

void cpv(std::vector<char>& A, int i, std::vector<char>& C, std::vector<char>& V,
         std::vector<bool>& uc, std::vector<bool>& uv)
{
  if (i == int(A.size())) print(A);
  else {
    for (int j = 0; j < int(C.size()); ++j) {
      if (not uc[j]) {
        A[i] = C[j];
        uc[j] = true;
        for (int k = 0; k < int(V.size()); ++k) {
          if (not uv[k]) {
            A[i+1] = V[k];
            uv[k] = true;
            cpv(A, i+2, C, V, uc, uv);
            uv[k] = false;
          }
        }
        uc[j] = false;
      }
    }
  }
}

int main()
{
  int n;
  std::cin >> n;

  std::vector<char> C(n);
  for (int i = 0; i < n; ++i) std::cin >> C[i];
  std::vector<char> V(n);
  for (int i = 0; i < n; ++i) std::cin >> V[i];

  std::vector<char> A(2*n);
  std::vector<bool> uc(n, false);
  std::vector<bool> uv(n, false);
  cpv(A, 0, C, V, uc, uv);
}
