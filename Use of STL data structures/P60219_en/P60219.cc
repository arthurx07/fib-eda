/* Consider the following game. You start with an empty set of words S. Afterwards,
* you will be given words one by one. For every given word w, if w is not in S,
* insert w in S, and if w is already in S, remove w from S. At the end of the process,
* you must list
*    the words that belong to S;
*    the words that have been in S, but that finally are not in S.
*/

#include <iostream>
#include <sstream>
#include <set>

struct length_compare
{
  bool operator() (const std::string& a, const std::string& b) const
  {
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
  }
};

int main()
{
  int game = 1;

  std::string w;
  while (w != "QUIT")
  {
    std::set<std::string> has;
    std::set<std::string, length_compare> had;

    while (std::cin >> w and w != "END" and w != "QUIT")
    {
      if (has.count(w))
      {
        has.erase(w);
        had.insert(w);
      }
      else
      {
        has.insert(w);
        had.erase(w);
      }
    }

    if (game > 1) std::cout << std::endl;
    std::cout << "GAME #" << game << std::endl << "HAS:" << std::endl;

    std::set<std::string>::iterator it;
    for (it = has.begin(); it != has.end(); ++it)
      std::cout << *it << std::endl;

    std::cout << std::endl << "HAD:" << std::endl;
    std::set<std::string, length_compare>::iterator nit;
    for (nit = had.begin(); nit != had.end(); ++nit)
         std::cout << *nit << std::endl;

    ++game;
  }
}

/* versió alternativa:
* map<string, bool> words, on a cada word es fa que words[w] = !words[w].
*/
