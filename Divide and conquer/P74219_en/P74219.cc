/* Fibonacci numbers (2)
* The input consists of several pairs of n and m. Assume 0 ≤ n ≤ 109 and 2 ≤ m ≤ 103.
* For every given pair, print Fn modm.
*/

#include <iostream>
#include <vector>

using matrix = std::vector<std::vector<unsigned int>>;

/* START: CODE TAKEN FROM P61833.cc */
matrix mod_matrix_mul(matrix A, matrix B, unsigned int m)
{
  matrix C(A.size(), std::vector<unsigned int>(B[0].size()));

  for (unsigned int i = 0; i < A.size(); ++i) {
    for (unsigned int j = 0; j < B[0].size(); ++j) {
      for (unsigned int k = 0; k < A[0].size(); ++k) C[i][j] += A[i][k]*B[k][j];
      C[i][j] %= m;
    }
  }

  return C;
}

matrix modular_pow(matrix B, unsigned int e, unsigned int m)
{
  matrix C = { {1,0}, {0,1} }; // Identity matrix (1)
  if (e == 0) return C;

  if (e%2) return mod_matrix_mul(B, modular_pow(B, e - 1, m), m);

  matrix D = modular_pow(B, e / 2, m);
  return mod_matrix_mul(D, D, m);
}
/* END: CODE TAKEN FROM P61833.cc */

int main()
{
  int n, m;
  while (std::cin >> n >> m)
  {
    matrix f = { {1, 1}, {1, 0} };
    matrix p = modular_pow(f, n, m);
    std::cout << p[0][1] << std::endl; // why is p[0][1]? (know by error-test)
    // in notes: p[1][0] + p[1][1]
  }
}

/* We can prove by induction that:
* [Fn+1]    =     ([1 1])^n   *  [F1]       as:  [F2] = [1 1]*[F1]
* [Fn  ]          ([1 0])        [F0]            [F1]   [1 0] [F0]
*
* As f is 0(1) and pow(f, n) is 0(logn) => calculating fibonacci numbers is 0(logn).
*/
