/* Satisfiability
 * Write a program to ﬁnd all the solutions to a set of m three–literal clauses
 *  c1, . . . , cm in conjunctive normal form.
 * For instance, {a = true, b = false, c = true, d = true} is a possible solution for the three clauses
   *  a or b or c, not a or b or c, b or not c or d.
 * As another example, {a = true, b = false} is a possible solution for the clause
   *  b or not a or a.
 * Strictly speaking, this clause does not have three literals (in fact it is
 *  equal to true, which has no literals at all), but in this exercise it is allowed
 *  to have repeated literals in the same clause.
 *
 * Input: Input consists of a natural number 1 ≤ n ≤ 20, followed by a natural
 *  number m > 0, followed by c1, …, cm. The names of the variables are the first
 *  n lowercase letters, and all of them appear in the input at least once. A negative
 *  literal is indicated by a minus symbol in front of the variable.
 *
 * Output: Print all the possible solutions of the set of clauses. The literals
 *  of each solution must appear in alphabetical order. If there is no solution,
 *  print a hyphen.
*/

#include <iostream>
#include <vector>

void print(std::vector<bool>& A)
{
  for (int i = 0; i < int(A.size()); ++i) {
    if (i > 0) std::cout << ' ';
    if (not A[i]) std::cout << '-';
    std::cout << char(i + 'a');
  }
  std::cout << std::endl;
}

bool eval(std::vector<bool>& A, std::vector<std::vector<std::pair<char, bool>>>& C)
{
  for (int i = 0; i < int(C.size()); ++i) {
    bool found = false;
    for (int j = 0; not found and j < 3; ++j) {
      int k = C[i][j].first - 'a';
      found = (C[i][j].second and A[k]) or (not C[i][j].second and not A[k]);
    }
    if (not found) return false;
  }
  return true;
}

bool satisfiability(std::vector<bool>& A, std::vector<std::vector<std::pair<char, bool>>>& C, int i)
{
  if (i == int(A.size()) and eval(A, C)) {
    print(A);
    return true;

  } else if (i < int(A.size())) {
    bool found = false;
    A[i] = true;
    found = satisfiability(A, C, i+1);

    A[i] = false;
    found = satisfiability(A, C, i+1) or found;
    return found;

  }
  return false;
}

int n;

void satisfiability(std::vector<std::vector<std::pair<char, bool>>>& C)
{
  std::vector<bool> A(n);
  if (not satisfiability(A, C, 0)) std::cout << '-' << std::endl;
}

int main()
{
  int m;
  std::cin >> n >> m;

  std::vector<std::vector<std::pair<char, bool>>> C(m, std::vector<std::pair<char, bool>>(3));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::string s;
      std::cin >> s;
      if (s[0] == '-') C[i][j] = std::make_pair(s[1], false);
      else C[i][j] = std::make_pair(s[0], true);
    }
  }
  
  satisfiability(C);
}
