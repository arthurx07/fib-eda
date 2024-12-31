/* Queens (2)
 * Write a program to print all the ways to place n queens on an nxn chessboard
 *  so that no queen threatens another queen.
 * Input: natural number n > 0
 * Output: number of ways ...where queens are marked with a 'Q' and empty positons
 *  with a dot.
*/

#include <iostream>
#include <vector>

void print(int n, std::vector<int>& t)
{
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      std::cout << (t[i] == j ? 'Q' : '.');
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void queens(int n, int i, std::vector<int>& t, std::vector<bool>& mc, 
           std::vector<bool>& mda, std::vector<bool>& mdd)
{
  if (i == n) print(n, t); // solution found (n queens in nxn chessboard ...)
  else {
    for (int j = 0; j < n; ++j) {
      if (not mc[j] and not mdd[i+j] and not mda[i-j+n-1]) {
        // if not in the same column, ascendent diagonal, descendent diagonal, than other queen
        t[i] = j;
        mc[j] = mdd[i+j] = mda[i-j+n-1] = true; // mark c, da, dd as used
        queens(n, i+1, t, mc, mda, mdd);
        mc[j] = mdd[i+j] = mda[i-j+n-1] = false; // free (restore) those c, da, dd for further backtracking
      }
    }
  }
}

void queens(int n)
{
  std::vector<int> t(n);
  std::vector<bool> mc(n, false);
  std::vector<bool> mda(2*n - 1, false);
  std::vector<bool> mdd(2*n - 1, false);

  queens(n, 0, t, mc, mda, mdd);
}

int main()
{
  int n;
  std::cin >> n;
  queens(n);
}

// EXPLAIN, using markings:
// vector<int> t: t[i] is the column of the queen in row i
// vector<bool> mc(n): mc[i] is true if there's a queen in column i
// vector<bool> mdd(2*n-1): mdd[k] is true if there's a queen in descendent
//    diagonal k. It is identified with i+j. Possible numbers are [0, 2n-2].
// vector<bool> mda(2*n-1): mda[k] is true if there's a queen in ascendent
//    diagonal k. It is identified with i-j+(n-1) [could be i-j, but to make it
//    easier ...]. Possible numbers are [0, 2n-2]

// Descendent diagonal example           Ascendent Diagonal example
//   0 1 2 3 4                            0 1 2 3 4
// 0 E F G H I                          0 A B C D E
// 1 D E F G H                          1 B C D E F
// 2 C D E F G                          2 C D E F G
// 3 B C D E F                          3 D E F G H
// 4 A B C D E                          4 E F G H I
//
// If we didn't use markings, we'd need to iterate over all the rows (and thus
//  c, da, dd) to check if the current position of the queen is 'legal'.
//
// Prunes:
// 1. If there are two queens in the same c, da, dd we discard that partial subtree.
