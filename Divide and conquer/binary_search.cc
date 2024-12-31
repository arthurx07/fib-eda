/* T(n) = Θ(logn) */
int binary_search (const vector<int>& a, int i, int j, int x)
{
  if (i > j) return -1;

  int k = (i + j)/2;
  if (x < a[k]) return binary_search(a, i, k-1, x);
  else if (x > a[k]) return binary_search(a, k+1, j, x);
  else return k;
}
