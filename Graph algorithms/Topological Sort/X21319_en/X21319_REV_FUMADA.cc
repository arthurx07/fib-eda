/* Circuit Value Problem
 * Verilog is a hardware description language to model digital circuits that is
 * standardized by IEEE. Write a program that, given the description of a digital
 * circuit in a simplified version of Verilog and a sequence of truth assignments
 * for the inputs to the circuit, outputs the result of evaluating the circuit
 * on those assignments.
 *
 * Follow the format of the examples. You may assume that the input describes a
 * correct circuit; that is, input and output cables are disjoint, all cables
 * are reachable from the inputs, and the circuit does not contain cycles (in
 * particular, no input cable is the output of a gate).
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using node = std::pair<std::string, std::string>; // pair(id, operator [for INPUT is undefined])
using graph = std::map<node, std::vector<std::string>>; // adjacency list

std::map<std::string, bool> eval(graph& G, std::vector<std::string>& I)
{
  std::map<std::string, int> edges;
  for (auto u : G)
    for (std::string w : G[u.first]) ++edges[w];

  std::priority_queue<node, std::vector<std::string>,
                      std::greater<std::string>> Q; // min_heap
  // If at this point the vertice does not have edges, it's an input.
  int i = 0;
  for (auto u : G) {
    if (not edges[u.first.first]) {
      u.first.second = I[i];
      ++i;
      Q.push(u.first);
    }
  }

  std::map<std::string, bool> O;
  // initialize O
  for (auto u : G) {
    if (u.first.second == "AND") O[u.first.first] = true;
    else if (u.first.second == "OR") O[u.first.first] = false;
  }

  while (not Q.empty()) {
    node u = Q.top();
    Q.pop();
    O[u.first] = O[u.first] or (u.second == "T");

    for (std::string w : G[u]) {
      if (G[w]->first.second == "OR") O[w.first] = O[w.first] or (u.second == "T");
      else if (G[w]->first.second == "AND") O[w.first] = O[w.first] and (u.second == "T");
      else if (G[w]->first.second == "NOT") O[w.first] = not (u.second == "T");

      if (not --edges[w.first]) Q.push(w);
    }
  }
  return O;
}

int main()
{
  graph G;

  std::string s;

  int no = 0;
  std::cin >> s; // OUTPUT
  for (; std::cin >> s and s != "END"; ++no); // G[s]; // s is OUTPUT_NAME

  int ni = 0;
  std::cin >> s; // INPUT
  for (; std::cin >> s and s != "END"; ++no); // G[s]; // s is INPUT_NAME

  while (std::cin >> s and s != "END") { // s is GATE
    if (s == "AND" or s == "OR") {
      std::string a, b, c;
      std::cin >> c >> a >> b;
      G[std::make_pair(c, s)];
      G[std::make_pair(a, "")].push_back(c);
      G[std::make_pair(b, "")].push_back(c);

    } else {
      std::string a, c;
      std::cin >> c >> a;
      G[std::make_pair(c, s)];
      G[std::make_pair(a, "")].push_back(c);
    }
  }

  char c;
  std::vector<std::string> inputs; 
  while (std::cin >> c) {
    inputs[0] = c; // (c == 'T');
    for (int i = 1; i < ni; ++i) {
      inputs[i] = c; // (c == 'T');
    }

    std::map<std::string, bool> outputs = eval(G, inputs);

    // for (int i = int(G.size()) - no; i < int(G.size()) + no; ++i) {
    for (node u : G) {
      if (outputs[u.first.first]) std::cout << "T";
      else std::cout << "F";

      std::cout << ' ';
      // if (i != no-1) std::cout << ' ';
    }
    std::cout << std::endl;
  }
}
