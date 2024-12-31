#include <iostream>
#include <vector>

int binary_first_search(double x, const std::vector<double>& v, int l, int r)
{
  if (l > r) return -1;
  int m = (l + r)/2;

  if (x < v[m] or (m > l and v[m-1] == x)) return binary_first_search(x, v, l, m-1);
  if (x > v[m]) return binary_first_search(x, v, m+1, r);

  return m;
}

int first_occurrence(double x, const std::vector<double>& v)
{
  return binary_first_search(x, v, 0, v.size() - 1);
}

int main() {
  int n;
  while (std::cin >> n)
  {
    std::vector<double> V(n);
    for (int i = 0; i < n; ++i) std::cin >> V[i];

    int t;
    std::cin >> t;
    while (t--) {
      double x;
      std::cin >> x;
      std::cout << first_occurrence(x, V) << std::endl;
    }
  }
}
