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
#include <stack>
#include <map>

using graph = std::vector<std::vector<int>>;

// Pre: G is an adjacency list of nodes i, info[i] returns operation of i (T, F, AND, OR, NOT)
std::vector<std::string> eval(graph &G, std::vector<std::string> info)
{
  int n = int(G.size());
  std::vector<int> de(n, 0);
  for (int u = 0; u < n; ++u) {
    for (int i = 0; i < int(G[u].size()); ++i)
      ++de[ G[u][i] ];
  }

  std::stack<int> S;
  for (int u = 0; u < n; ++u)
    if (de[u] == 0) S.push(u);

  // u is a degree 0 vertice, i.e. it's a literal T or F.
  while (not S.empty()) {
    int u = S.top();
    S.pop();

    // if u is AND, meaning no vertice which points to them is F, u is T
    if (info[u] == "AND") info[u] = "T";
    // if u is OR, meaning no vertice which points to them is T, u is F
    else if (info[u] == "OR") info[u] = "F";

    for (int v : G[u]) {
      if (--de[v] == 0) S.push(v);

      if (info[u] == "T") {
        if (info[v] == "OR") info[v] = "T";
        else if (info[v] == "NOT") info[v] = "F";

      } else if (info[u] == "F") {
        if (info[v] == "AND") info[v] = "F";
        else if (info[v] == "NOT") info[v] = "T";
      }
    }
  }
  return info;
}

int main()
{
  graph G;
  std::string s;
  std::map<std::string, int> M; // map (name -> index)

  int no = 0;
  std::cin >> s;
  if (s == "OUTPUT") {
    for (; std::cin >> s and s != "END"; ++no) { // s is output_name
      M[s] = no;
      G.push_back(std::vector<int>());
    }
  }

  int ni = 0;
  std::cin >> s;
  if (s == "INPUT") {
    for (; std::cin >> s and s != "END"; ++ni) { // s is input_name
      M[s] = ni + no;
      G.push_back(std::vector<int>());
    }
  }

  std::vector<std::string> info(ni + no, ""); // vector [index] = value;
  for (int i = ni + no; std::cin >> s and s != "END"; ) { // s is gate
    std::string x, y;
    std::cin >> x >> y;

    if (not M.count(x)) { // if x has not been mapped to an index
      G.push_back(std::vector<int>());
      info.push_back(s);
      M[x] = i++;
    }
    else if (info[M[x]] == std::string()) info[M[x]] = s;

    if (not M.count(y)) {
      G.push_back(std::vector<int>());
      info.push_back(std::string());
      M[y] = i++;
    }
    G[M[y]].push_back(M[x]);

    if (s == "AND" or s == "OR") {
      std::string z;
      std::cin >> z;

      if (not M.count(z)) {
        G.push_back(std::vector<int>());
        info.push_back(std::string());
        M[z] = i++;
      }
      G[M[z]].push_back(M[x]);
    }
  }

  std::string c;
  while (std::cin >> c) {
    info[no] = c;
    for (int i = no + 1; i < no + ni; ++i) {
      std::cin >> c;
      info[i] = c;
    }

    std::vector<std::string> info_eval = eval(G, info);

    for (int i = 0; i < no; ++i) {
      if (i > 0) std::cout << ' ';
      std::cout << info_eval[i];
    }
    std::cout << std::endl;
  }
}

/* APRENDIDO EN ESTE EJERCICIO DE ORDENACIÓN TOPOLÓGICA
 * 1. Siempre se debe crear un dag con una lista de adyacencias de tal manera
 *    que a1 -> a2, donde al pasar por a1 se actualiza el valor de a2 (en el
 *    caso de este ej).
*/
