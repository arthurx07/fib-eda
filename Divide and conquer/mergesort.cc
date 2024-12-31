#include <vector>

/* T(n) = Θ(n), where n = d-e+1 */
template <typename T>
void merge (vector<T>&v, int left, int mid, int right)
{
  int n = right - left + 1;
  vector<T> aux(n);

  int i = left;
  int j = mid + 1;
  int k = 0;
  while (i <= mid and j <= right) {
    if (v[i] <= v[j]) aux[k++] = v[i++];
    else aux[k++] = v[j++];
  }
  while (i <= mid) aux[k++] = v[i++];
  while (j <= right) aux[k++] = v[j++];
  for (k = 0; k < n; ++k) v[left+k] = aux[k];
}

/* T(n) = Θ(nlog(n)) */
template <typename T>
void merge_sort (vector<T>& a, int e, int d)
{
  if (e < d)
  {
    int m = (e + d)/2;
    merge_sort(a, e, m);
    merge_sort(a, m + 1, d);
    merge(a, e, m, d); // 0(n) for each recursive step
  }
}

template <typename T>
void mergosrt(vector<T>& a)
{
  mergesort(a, 0, a.size()-1);
}
