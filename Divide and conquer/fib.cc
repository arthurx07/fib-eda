#include <iostream>
#include <vector>

using matrix = std::vector<std::vector<unsigned int>>;

matrix product(matrix A, matrix B)
{
  matrix C(A.size(), std::vector<unsigned int>(B[0].size()));

  for (unsigned int i = 0; i < A.size(); ++i) {
    for (unsigned int j = 0; j < B[0].size(); ++j) {
      for (unsigned int k = 0; k < A[0].size(); ++k) C[i][j] += A[i][k]*B[k][j];
    }
  }

  return C;
}

matrix pow(matrix& x, unsigned int k)
{
  if (k == 0) return {{1, 0}, {0, 1}};

  matrix y = pow(x, k/2);
  if (k%2 == 0) return product(y, y);
  return product(product(y, y), x);
}

/* F0 = 0, F1 = 1,
 * and
 * Fn = Fn-1 + Fn-2
 * for n > 1
 *
 * This algorithm has cost Θ(logn).
*/
unsigned int fib(unsigned int n)
{
  matrix f = { {1, 1}, {1, 0} };
  matrix p = pow(f, n ? n-1 : 0);
  return p[1][0] + p[1][1];
}

int main()
{
  unsigned int n;

  while (std::cin >> n)
    std::cout << fib(n) << std::endl;
}
