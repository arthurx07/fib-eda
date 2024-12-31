/* Collection of numbers
Write a program to keep a collection of integer numbers, perhaps with repetitions, while performing the following operations:
    ‘S’ x : Stores a copy of the given number x.
    ‘A’ : Asks for the greatest number.
    ‘R’ : Removes the greatest number (one of them, if it is repeated).
    ‘I’ x : Increases the greatest number (one of them, if it is repeated) in x units.
    ‘D’ x : Decreases the greatest number (one of them, if it is repeated) in x units.
Outut: For every query, the current greatest number. Print also an error line for each operation (except storing) when the collection is empty.
*/
#include <queue>
#include <iostream>

int main()
{
  std::priority_queue<int> pq;
  /* a priority queue is like a heap where elements can be inserted and only
  * the max_heap (the one at the top) can be retrieved */

  char c;
  while (std::cin >> c)
  {
    if (c == 'S')
    {
      int x;
      std::cin >> x;
      pq.push(x);
    }
    else if (not pq.empty()) 
    {
      if (c == 'A') std::cout << pq.top() << std::endl;
      else if (c == 'R') pq.pop();
      else if (c == 'I')
      {
        int x;
        std::cin >> x;
        x += pq.top();
        pq.pop();
        pq.push(x);
      }
      else if (c == 'D')
      {
        int x;
        std::cin >> x;
        x = pq.top() - x;
        pq.pop();
        pq.push(x);
      }
    }
    else 
    {
      std::cout << "error!" << std::endl;
      if (c == 'I' or c == 'D') 
      {
        int x;
        std::cin >> x;
      }
    }
  }
}
