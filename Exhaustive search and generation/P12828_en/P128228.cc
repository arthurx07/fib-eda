/*  Zeros and ones (1) [Merry Christmas!]
Write a backtracking program to print all the combinations of z zeros and o ones
  such that z + o = n, for a given n.
  - Input consists of a natural number n > 0.
  - Print all the combinations of z zeros and o ones such that z + o = n, one per
      line and in lexicographical order.

Obs: Although a backtracking program is not really necessary to solve this exercise,
  implement it anyway for the sake of practice.
*/

#include <iostream>
#include <vector>

void print(std::vector<int>& V)
{
  for (int i = 0; i < int(V.size()); ++i) {
    if (i > 0) std::cout << ' ';
    std::cout << V[i];
  }
  std::cout << std::endl;
}

void binary(std::vector<int>& A, int i)
{
  if (i == int(A.size()))
    print(A);
  else {
    A[i] = 0;
    binary(A, i+1);

    A[i] = 1;
    binary(A, i+1);
  }
}

void binary(int n)
{
  std::vector<int> A(n);
  binary(A, 0);
}

int main()
{
  int n;
  std::cin >> n;
  binary(n);
}
