/* Equal sums (2)
 * Write a program that, given an integer number s and n integer numbers x1, …, xn,
 *  prints the subset (maybe with repeated numbers, but using every xi at most once)
 *  lexicographically largest among those whose sum is s.
 *  If there is none, print “no solution”.
 *
 * Hint: sort the given numbers
*/

#include <algorithm>
#include <iostream>
#include <vector>

void print(std::vector<int>& A)
{
  std::cout << '{';
  for (int i = 0; i < int(A.size()); ++i) {
    if (i > 0) std::cout << ',';
    std::cout << A[i];
  }
  std::cout << '}' << std::endl;
}

// Prunings:
// 1. if current sum + rest sum < s => this branch will never sum s. 
// 2. if current sum > s => this branch will never sum s.

// i: current position in X vector.
bool equal_sum(std::vector<int>& A, std::vector<int>& X, int s, int cs, int i)
{
  if (cs == s and i == int(X.size())) {
    print(A); // only print when checked all elements
    return true;
  }
  else if (i < int(X.size())){
    A.push_back(X[i]);
    if (equal_sum(A, X, s, cs + X[i], i+1)) return true;
    A.pop_back();
    if (equal_sum(A, X, s, cs, i+1)) return true;
  }
  return false;
}

void equal_sum(std::vector<int>& X, int s)
{
  std::vector<int> A;
  if (not equal_sum(A, X, s, 0, 0)) std::cout << "no solution" << std::endl;
}

int main()
{
  int s, n;
  std::cin >> s >> n;

  std::vector<int> X(n);
  for (int i = 0; i < n; ++i) std::cin >> X[i];

  // std::sort(X.begin(), X.end(), std::greater<unsigned int>());
  std::sort(X.rbegin(), X.rend());

  equal_sum(X, s);
}
