/* Powers of permutations
*   The input includes several cases. Each case consists in the number n (1 ≤ n ≤ 104),
*   followed by n numbers between 1 and n that describe the permutation σ, followed
*   by the number k (0 ≤ k ≤ 109).The input includes several cases. Each case
*   consists in the number n (1 ≤ n ≤ 104), followed by n numbers between 1 and n
*   that describe the permutation σ, followed by the number k (0 ≤ k ≤ 109).
*
*   Write the permutation σ^k. The expected solution to this problem has cost O(n · logk).
*/
#include <iostream>
#include <vector>
// #include <algorithm>

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

// Pre: s and t are permutations of size s.size() == t.size()
std::vector<int> product(std::vector<int> s, std::vector<int> t)
{
  std::vector<int> r(s.size());
  for (int i = 0; i < int(s.size()); ++i)
    r[i] = s[ t[i] ];
  return r;
}

std::vector<int> pow(std::vector<int> r, int k)
{
  if (k == 0) {
    // std::sort(r.begin(), r.end());
    quicksort(r);
    return r;
  }

  std::vector<int> u = pow(r, k/2);
  if (k%2 == 0) return product(u, u);
  return product(product(u, u), r);
}

int main()
{
  int n;
  while (std::cin >> n)
  {
    std::vector<int> r(n);
    for (int i = 0; i < n; ++i) std::cin >> r[i];

    int k;
    std::cin >> k;

    r = pow(r, k);
    for (int i = 0; i < n; ++i) {
      std::cout << r[i];
      if (i != n-1) std::cout << ' ';
    }
    std::cout << std::endl;
  }
}

/*
Given an n, a permutation of {0, 1, … n−1} is a sequence where each of the numbers 0, 1, … n−1 occurs exactly once. For example, if n = 3, the sequences (1 2 0), (2 0 1) and (0 1 2) are permutations of {0, 1, 2}.
Given two permutations σ(sigma s) = (σ0, …, σn−1) and τ(tau t) = (τ0, …, τn−1) of {0, 1, … n−1 }, their product σ ∘ τ is defined as the permutation ρ(rho r) = (ρ0, …, ρn−1) such that ρi = στi. For example, if n = 3, σ = (1 2 0) and τ = (2 0 1), then σ ∘ τ = (0 1 2), since:
    τ0 = 2 and σ2 = 0,
    τ1 = 0 and σ0 = 1, and
    τ2 = 1 and σ1 = 2. 
Make a program that, given a permutation σ and a natural k, computes the power of σ raised to k: σk = σ ∘ … ∘ σk). By convention, σ0 = (0, 1, …, n−1).
*/
