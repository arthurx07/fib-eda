/* Sudoku
 * Tercer Concurs de Programació de la UPC - Semifinal (2005-09-14)
 * The rules are easy: You are given a 9 × 9 grid with some numbers in it, and you should fill
 *  in the grid so that every row, every column and every 3 × 3 box contains the numbers from
 *  1 to 9.
 *
 * Write a program to solve Sudoku puzzles. These are guaranteed to have a unique solution.
 *
 * Input: Begins with a line with a number n ≥ 1. Follow n Sudokus, each one consisting of
 *  nine lines, each one with nine space-separated characters, which are digits from 1 to 9 and
 *  dots. The latter indicate cells that are still empty. There is a blank line before every puzzle.
 *
 * Output: Print the solutions using the same format as in the input: First, print n on a line. For each
 *  puzzle, print nine lines, each with nine digits separated by spaces. Print a blank line before
 *  every solution.
*/

#include <iostream>
#include <vector>

void print(std::vector<std::vector<int>>& S)
{
  for (int i = 0; i < 9; ++i) {
    for (int j= 0; j < 9; ++j) {
      if (j > 0) std::cout << ' ';
      std::cout << S[i][j];
    }
    std::cout << std::endl;
  }
}

// i is a row or column, returns the upper left coordinate row or column of the box.
int box(int i)
{
  if (i < 3) return 0;
  if (i >= 3 and i < 6) return 3;
  if (i >= 6) return 6;
  return -1;
}

bool legal(std::vector<std::vector<int>>& S, int k, int i, int j)
{
  for (int a = 0; a < 9; ++a) {
    if (S[i][a] == k and a != j) return false; 
    if (S[a][j] == k and a != i) return false;
  }

  for (int a = box(i); a < box(i) + 3; ++a) {
    for (int b = box(j); b < box(j) + 3; ++b)
      if (S[a][b] == k and a != i and b != j) return false;
  }

  return true;
}

void solve(std::vector<std::vector<int>>& S, int i, int j, bool& found)
{
  if (S[i][j] == 0 and not found) {
    for (int k = 1; not found and k <= 9; ++k) { // k is a number
      if (legal(S, k, i, j)) {
        S[i][j] = k;
        if (j < 8) solve(S, i, j+1, found);
        else if (i < 8) solve(S, i+1, 0, found);
        else {
          print(S);
          found = true;
        }
        S[i][j] = 0; // reset for further backtracking
      }
    }

  } else if (not found){ // skip cell
    if (j < 8) solve(S, i, j+1, found);
    else if (i < 8) solve(S, i+1, 0, found);
    else {
      print(S);
      found = true;
    }

  }
}

// Solves a sudoku S.
void solve(std::vector<std::vector<int>>& S)
{
  bool found = false;
  solve(S, 0, 0, found);
}

int main()
{
  int n;
  std::cin >> n;
  std::cout << n << std::endl;
  for (int i = 0; i < n; ++i) {
    std::cout << std::endl;
    std::vector<std::vector<int>> S(9, std::vector<int>(9, 0));
    for (int j = 0; j < 9; ++j) {
      for (int k = 0; k < 9; ++k) {
        char c;
        std::cin >> c;
        if (c != '.') S[j][k] = c - '0';
      }
    }

    solve(S);
  }
}
