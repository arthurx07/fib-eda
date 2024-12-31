/* Simulate a server of a role-playing game for two Players. Each Player has an “elo”, which is a value larger the better is the Player. Everyone starts with 1200 points, and nobody ever gets a lower quantity, no matter how many games are lost. Whenever there is a match, the winner gets 10 elo points, and the loser loses 10 elo points (with the limitation above). The elo of a Player is kept when he or she disconnects from the server.

We have these instructions:

    “LOGIN” j : The Player j starts a session. Ignore it if the Player is already connected.
    “LOGOUT” j : The Player j closes the session. Ignore it if the Player is not connected.
    “PLAY” j1  j2 : Indicates that j1 has beaten j2, with j1 ≠ j2. Ignore it but print an error message if any of the two Players is not connected.
    “GET_ELO” j : Print the Player j (who was connected for sure previously, although now may be disconnected) with his or her current elo.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

struct Player {
  std::string name;
  int elo = 1200;
  bool connected = true;
};

bool cmp(const Player& a, const Player& b)
{
  // condition ? expression-true : expression-false
  return (a.elo == b.elo) ? a.name < b.name : a.elo > b.elo;
};

int main()
{
  std::map<std::string, int> m;
  std::vector<Player> v;
  std::string s;

  while (std::cin >> s)
  {
    if (s == "LOGIN")
    {
      std::string p;
      std::cin >> p;
      Player pl;
      pl.name = p;

      if (m.count(p)) v[m[p]].connected = true;
      else
      {
        v.push_back(pl);
        m.insert( std::pair<std::string, int>(p, v.size()-1) );
      }
    }
    else if (s == "LOGOUT")
    {
      std::string p;
      std::cin >> p;
      if (m.count(p)) v[ m[p] ].connected = false;
    }
    else if (s == "PLAY")
    {
      std::string p1, p2;
      std::cin >> p1 >> p2;
      if (m.count(p1) and m.count(p2) and v[m[p1]].connected and v[m[p2]].connected)
      {
        v[ m[p1] ].elo += 10;
        v[ m[p2] ].elo = v[m[p2]].elo < 1210 ? 1200 : v[m[p2]].elo - 10;
      }
      else std::cout << "player(s) not connected" << std::endl;
    }
    else if (s == "GET_ELO")
    {
      std::string p;
      std::cin >> p;
      std::cout << p << ' ' << v[ m[p] ].elo << std::endl;
    }
  }

  std::cout << std::endl << "RANKING" << std::endl;
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < v.size(); ++i)
    std::cout << v[i].name << ' ' << v[i].elo << std::endl;
}
