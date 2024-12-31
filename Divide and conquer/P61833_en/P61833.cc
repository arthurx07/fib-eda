/* Powers of a matrix
* Input consists of several cases, each with M11, M12, M21 and M22 in this order,
*   followed by n and m. Assume that the elements of M are not larger than 500,
*   0 ≤ n ≤ 109, and 2 ≤ m ≤ 1000.
* For every case, print the elements of Mn modm in two lines following the format
*   of the sample. Print a line with 10 dashes after every matrix.
*/

// See P29212.cc for an explication on Modular Exponentiation.
// This exercise is solved by the same principle, but applied to matrices.

#include <iostream>
#include <vector>

using matrix = std::vector<std::vector<unsigned int>>;

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

/* Recursive option taken from https://en.wikipedia.org/wiki/Modular_exponentiation#Generalizations */
matrix modular_pow(matrix B, unsigned int e, unsigned int m)
{
  matrix C = { {1,0}, {0,1} }; // Identity matrix (1)
  if (e == 0) return C;

  if (e%2) return mod_matrix_mul(B, modular_pow(B, e - 1, m), m);

  matrix D = modular_pow(B, e / 2, m);
  return mod_matrix_mul(D, D, m);
}

/* Iterative option adapted from P29212.cc (slightly worse?) */
/* matrix modular_pow(matrix B, unsigned int e, unsigned int m)
{
  if (m == 1) return matrix();

  matrix C = { {1,0}, {0,1} }; // Identity matrix (1)
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
       B[i][j] %= m;
  
  for (; e > 0; e >>= 1)
  {
    if (e%2) C = mod_matrix_mul(C, B, m); 
    B = mod_matrix_mul(B, B, m);
  }
  return C;
} */

int main()
{
  matrix M(2, std::vector<unsigned int> (2));

  int n, m;
  while (std::cin >> M[0][0] >> M[0][1] >> M[1][0] >> M[1][1] >> n >> m)
  {
    M = modular_pow(M, n, m);

    for (unsigned int i = 0; i < M.size(); ++i) {
      for (unsigned int j = 0; j < M[0].size(); ++j) {
        std::cout << M[i][j];
        if (j == 0) std::cout << ' ';
      }
      std::cout << std::endl;
    }

    std::cout << "----------" << std::endl;
  }
}
