/*
 * When a supporter asks for a ticket, if there is any available at that moment,
 * the supporter immediately gets one. Otherwise, the supporter’s code is recorded.
 * When a ticket is available, if there is no recorded code at that moment, the
 * ticket is stored. Otherwise, the ticket is given to the supporter with the shortest code.
 *
 * Ties are broken as follows: A fixed word w is arbitrarily chosen at the
 * beginning of the process. Then, lexicographical order is used among codes of
 * length n, except that w[1..n] is considered the first code, and the rest are
 * considered cyclically. For instance, if n = 4 and w[1..4] = “abcd”, then codes
 * of length 4 are sorted in this order: “abcd”, “abce”, …, “abcz”, “abda”, …,
 * “abdz”, …, “zzzz”, “aaaa”, …, “abcc”.
 */

#include <iostream>
#include <set>

std::string w;

struct ShorterString {
  bool operator()(const std::string& a, const std::string& b) const
  {
    if (a.length() == b.length())
    {
      std::string v = w.substr(0, a.length());
      return (a == v) or (a < b and v > a and v > b) or (v < a and v < b and a < b) or (v < a and b < v and a > b);
    }
    return a.length() < b.length();
  }
};

int main()
{
  while (std::cin >> w)
  {
    char c;
    int tickets = 0;
    std::set<std::string, ShorterString> supporters;
    while (std::cin >> c and c != 'E')
    {
      if (c == 'S')
      {
        std::string code;
        std::cin >> code;
        if (tickets > 0)
        {
          std::cout << code << std::endl;
          --tickets;
        }
        else supporters.insert(code);
      }
      else if (c == 'T')
      {
        if (supporters.empty()) ++tickets;
        else
        {
          std::cout << *supporters.begin() << std::endl;
          supporters.erase(supporters.begin());
        }
      }
    }
    std::cout << tickets << " ticket(s) left" << std::endl;
    std::cout << supporters.size() << " supporter(s) with no ticket" << std::endl;
    std::cout << std::endl;
  }
}
