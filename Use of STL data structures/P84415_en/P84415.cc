/*
You have an initially empty bag, where you can store words, and from where you
can delete words. Words can be repeated. Deleting a word means removing one of
its appearances. Deleting a nonexistent word does not have any effect. At any
moment you can be asked for the (lexicographically) greatest word of the bag,
and how many times it is repeated. You can also be asked for the same about the
smallest word.
*/

#include <map>
#include <iostream>

int main()
{
  std::map<std::string, int> m;
  std::string s;
  while (std::cin >> s)
  {
    if (s[0] == 'm')
    {
      s.pop_back();
      if (not m.empty())
      {
        std::map<std::string, int>::iterator it = m.begin();
        if (s[1] == 'a') it = --m.end(); // same as m.rbegin(), reverse_iterator

        std::cout << s << ": " << it->first << ", " << it->second << " time(s)" << std::endl;
      }
      else std::cout << "indefinite " << s << std::endl;
    }
    else
    {
      std::string w;
      std::cin >> w;
      if (s[0] == 's') ++m[w]; // ints are default constructed as 0 (int x = int() [= 0])
      else if (s[0] == 'd' and --m[w] <= 0) m.erase(w);
      /* not using --m.at(w), as throws out-of-range exception when element not exists
       * error: if item not exists, in this condition it is created and then eliminated instantly */
    }
  }
}
