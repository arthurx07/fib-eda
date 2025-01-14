// Write a program such that, for every given natural number n, prints all the different ways to obtain n cents with the euro system of coins (1 cent, 2 cents, 5 cents, 10 cents, 20 cents, and 50 cents).

// Input: Sequence of natural numbers 1 <= n <= 50.
// Output: For every n, print all the ways to obtain n cents, each one in a different line. The numbers of each line must appear in nonincreasing order. The solutions for every n must appear in reverse lexicographical order. Print an empty line after the output for each case.
// Observation: A simple backtracking program that computes the result for every given n (even if repeated) is fast enough for this problem.

#include <iostream>
#include <vector>

using namespace std;

// Given a vector of integers, print it with spaces
void print(vector<int> &A)
{
  for (int i = 0; i < int(A.size()); ++i) {
    if (i > 0) cout << ' ';
    cout << A[i];
  }
  cout << endl;
}

// Backtracking to compute the ways to obtain n cents
// n: sum to obtain, s: current sum, A: solution vector, C: possible coins, i: current index of C
void compute_ways(int n, int s, vector<int> &A, vector<int> &C, int i)
{
  if (s == n) print(A);
  else if (s < n) {
    for (int j = i; j < int(C.size()); ++j) {
      A.push_back(C[j]);
      compute_ways(n, s + C[j], A, C, j);
      A.pop_back();
    }
  }
}

// Print (and compute) all the ways to obtain n cents
void compute_ways(int n)
{
  vector<int> A;
  vector<int> C = {50, 20, 10, 5, 2, 1};
  compute_ways(n, 0, A, C, 0);
}

int main()
{
  int n;
  while (cin >> n) {
    compute_ways(n);
    cout << endl;
  }
}
