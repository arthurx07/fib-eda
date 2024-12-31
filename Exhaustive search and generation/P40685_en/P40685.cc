/* Equal sums (1)
 * Write a program that, given an integer number s and n integer numbers x1, …, xn,
 *  prints all the subsets (maybe with repeated numbers, but using every xi at most once)
 *  whose sum is exactly s.
 * 
 * Hint: For this exercise, simple backtracking solutions are accepted. No
 *  optimizations are required.
*/

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

// i: current position in X vector.
void equal_sums(std::vector<int>& A, std::vector<int>& X, int s, int sum, int i)
{
  if (sum == s and i == int(X.size())) print(A); // s != 0, to enter recursion when s == 0.
  else if (i < int(X.size())) { // if we are not at the end of X
    equal_sums(A, X, s, sum, i+1); // continue without X[i] in the sum
    A.push_back(X[i]);
    equal_sums(A, X, s, sum + X[i], i+1); // continue with X[i] in the sum
    A.pop_back();
    // We only try each sum combination once, as we iterate over the X vector once.
  }
}

void equal_sums(std::vector<int>& X, int s)
{
  std::vector<int> A;
  equal_sums(A, X, s, 0, 0);
}

int main()
{
  int s, n;
  std::cin >> s >> n;

  std::vector<int> X(n);
  for (int i = 0; i < n; ++i) std::cin >> X[i];

  equal_sums(X, s);
}
