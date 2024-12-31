/* Zeroes and ones (2)
Write a program to print all the combinations of n−o zeros and o ones, for some
  given n and o.
  - Input consists of n and o, two natural numbers such that n > 0 and 0 ≤ o ≤ n.
  - Output: Print all the combinations of n − o zeros and o ones, one per line and
      in lexicographical order.
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

// Prunes:
// 1. We detect situations where the chain has already all desired ones set.
// 2. We detect situations where the chain has already all desired zeroes set.

// A: partial chain (of size n)
// i: first chain not filled of A
// z: current number of zeroes in A[i...i-1]
// u: current number of ones in A[0...i-1]
// o: total number of desired ones
void chains(std::vector<int>& A, int i, int z, int u, int o)
{
  if (i == int(A.size())) print(A);
  else {
    if (z < int(A.size()) - o) { // there are 0s to be set
      A[i] = 0;
      chains(A, i+1, z+1, u, o);
    }

    if (u < o) { // there are 1s to be set
      A[i] = 1;
      chains(A, i+1, z, u+1, o);
    }
  }
}

void chains(int n, int o)
{
  std::vector<int> A(n);
  chains(A, 0, 0, 0, o);
}

int main()
{
  int n, o;
  std::cin >> n >> o;

  chains(n, o);
}
