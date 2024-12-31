/* Write a program to compute the most common statistical measures (minimum, 
 * maximum and average) of several integer numbers. These numbers are known 
 * increasingly. At every moment, it is also possible to delete the smallest 
 * element.
 */

#include <iostream>

/* Option 1
#include <queue>
int main()
{
  std::cout.setf(std::ios::fixed);
  std::cout.precision(4);

  std::priority_queue<int, std::vector<int>, std::greater<int>> pq; // can be std::vector<int> or std::deque<int>
  // we set greater to define we want the priority ordered as: max...min, where min=pq.top()
  std::string s;
  int max = 0;
  double sum = 0;
  while(std::cin >> s)
  {
    if (s == "number")
    {
      int x;
      std::cin >> x;

      if (pq.empty()) max = x;
      else max = std::max(max, x);

      sum += x;
      pq.push(x);
    }
    else if (s == "delete" and not pq.empty())
    {
      sum -= pq.top();
      pq.pop();
    }

    if (pq.empty()) std::cout << "no elements" << std::endl;
    else std::cout << "minimum: " << pq.top() << ", maximum: " << max << ", average: " << sum/pq.size()<< std::endl;
  }
}
*/

// Option 2
#include <set>
int main()
{
  std::cout.setf(std::ios::fixed);
  std::cout.precision(4);

  std::multiset<int> ms;
  std::string s;
  double sum = 0;
  while (std::cin >> s)
  {
    if (s == "number")
    {
      int x;
      std::cin >> x;

      sum += x;
      ms.insert(x);
    }
    else if (s == "delete" and not ms.empty())
    {
      sum -= *(ms.begin());
      ms.erase(ms.begin());
    }

    if (ms.empty()) std::cout << "no elements" << std::endl;
    else std::cout << "minimum: " << *(ms.begin()) << ", maximum: " << *(ms.rbegin()) << ", average: " << sum/ms.size()<< std::endl;
  }
}
