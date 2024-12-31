#include <vector>

template <typename T>
int partition(std::vector<T>& v, int l, int r)
{
  T p = v[l];
  int i = l - 1;
  int j = r + 1;

  for (;;)
  {
    while (v[++i] < p);
    while (p < v[--j]);
    if (j <= i) return j;
    std::swap(v[i], v[j]);
  }
}

template <typename T>
void quicksort(std::vector<T>& v, int l, int r)
{
  if (l < r)
  {
    int p = partition(v, l, r);
    quicksort(v, l, p);
    quicksort(v, p+1, r);
  }
}

template <typename T>
void quicksort(std::vector<T>& v)
{
  quicksort(v, 0, v.size()-1);
}
