/* T(n) = Θ(n) */
int linear_search (const vector<int>& a, int n, int x)
{
  if (n == 0) return -1;
  else if (a[n-1] == x) return n-1;
  else return cerca_lineal(a, n-1, x);
}
