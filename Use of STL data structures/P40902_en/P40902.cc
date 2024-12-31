/*
Write a program to compute the profits of the players of a casino. The operations
that can be done are: enter the casino, leave the casino, or win a quantity
(maybe negative) of money.
*/

#include <map>
#include <iostream>

int main()
{
  std::map<std::string, int> m;
  std::string name, op;
  while (std::cin >> name >> op)
  {
    if (op == "enters") {
      if (not m.count(name)) m[name] = 0;
      else std::cout << name << " is already in the casino" << std::endl;
    }
    else if (not m.count(name))
    {
      if (op == "wins") std::cin >> op;
      std::cout << name << " is not in the casino" << std::endl;
    }
    else if (op == "leaves")
    {
      std::cout << name << " has won " << m[name] << std::endl;
      m.erase(name);
    }
    else if (op == "wins") 
    {
      int x;
      std::cin >> x;
      m[name] += x;
    }
  }

  std::cout << "----------" << std::endl;
  std::map<std::string, int>::iterator it = m.begin();
  for (; it != m.end(); ++it)
    std::cout << it->first << " is winning " << it->second << std::endl;
}
