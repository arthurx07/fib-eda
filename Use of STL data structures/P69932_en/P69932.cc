/* You are given several natural numbers. Put some of the numbers side by side according to these rules:
    * the resulting sequence must be increasing;
    * there cannot be two even numbers together nor two odd numbers together. 
 *
 * Write a program such that, for every given line, prints the length of the longest sequence that can be produced according to the rules above using the numbers on that line.
 */

#include <iostream>
#include <set>
#include <sstream>

int main()
{
  for (std::string line; getline(std::cin, line);)
  {
    std::istringstream iss(line);

    std::set<int> s;
    for (int n; iss >> n;) s.insert(n); // elements are inserted ordered within the set

    int c = 0;
    if (not s.empty())
    {
      ++c;
      int prev = *s.begin()%2; // 1 if odd, 0 if even
      for (std::set<int>::iterator it = ++s.begin(); it != s.end(); ++it)
      {
        c += prev^(*it%2); // prev xor actual (don't sum if different parity)
        prev = *it%2;
      }
    }
    std::cout << c << std::endl;
  }
}
