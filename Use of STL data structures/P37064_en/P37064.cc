/* Given a sequence of words, print the median of all the words seen so far at
 * every moment. Please recall that the median of a set of n elements is the
 * element that would be in the position ⌊ (n + 1)/ 2 ⌋ if the set was ordered.
*/

#include <set>
#include <iostream>

int main()
{
  std::string w;
  std::set<std::string> s;
  std::set<std::string>::iterator m = s.end();
  while (std::cin >> w and w != "END")
  {
    s.insert(w);
    if (m == s.end()) --m; // base case, when s.size() == 1
    else if (s.size()%2 and *m < w) ++m;
    else if (not (s.size()%2) and *m > w) --m;
    // (?)  (not s.size()%2) == (not (s.size()%2))
    std::cout << *m << std::endl;
  }
}
/* There are four possible cases
 * 1. x y (z), as (4/2 = 2). s%2!=0 and *m<w => +
 *    * ^
 * 2. (z) x  y, as (4/2 = 2). s%2!=0 and *m>w => /
 *        ^*
 * 3. x y  z (a), as (5/2 = 2). s%2==0 and *m<w => /
 *      ^*
 * 4. (a) x y z, as (5/2 = 2). s%2==0 and *m>w => -
 *        ^ *
 */
