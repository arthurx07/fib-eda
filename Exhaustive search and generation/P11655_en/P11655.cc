/* Equal sums (3)
 * Write a program that, given an integer number s and n integer numbers x1, …, xn,
 *  prints all the subsets (maybe with repeated numbers, but using every xi at most once)
 *  whose sum is exactly s.
 * 
 * Hint: For this exercise, a very simple algorithm can be too slow. 
*/

#include <iostream>
#include <vector>

void print(std::vector<unsigned int>& A)
{
  std::cout << '{';
  for (unsigned int i = 0; i < (unsigned int)A.size(); ++i) {
    if (i > 0) std::cout << ',';
    std::cout << A[i];
  }
  std::cout << '}' << std::endl;
}

// Prunings:
// 1. if current sum + rest sum < s => this branch will never sum s. 
// 2. if current sum > s => this branch will never sum s.

// i: current position in X vector.
void equal_sums(std::vector<unsigned int>& A, std::vector<unsigned int>& X, unsigned int s, unsigned int cs, unsigned int rs, unsigned int i)
{
  if (cs <= s and cs + rs >= s) {
    if (i == (unsigned int)X.size()) print(A); // only print when checked all elements
    else {
      equal_sums(A, X, s, cs, rs - X[i], i+1);
      A.push_back(X[i]);
      equal_sums(A, X, s, cs + X[i], rs - X[i], i+1);
      A.pop_back();
    }
  }
}

void equal_sums(std::vector<unsigned int>& X, unsigned int s, unsigned int rs)
{
  std::vector<unsigned int> A;
  equal_sums(A, X, s, 0, rs, 0);
}

int main()
{
  unsigned int s, n;
  std::cin >> s >> n;

  unsigned int rs = 0;
  std::vector<unsigned int> X(n);
  for (unsigned int i = 0; i < n; ++i) {
    std::cin >> X[i];
    rs += X[i];
  }

  equal_sums(X, s, rs);
}
