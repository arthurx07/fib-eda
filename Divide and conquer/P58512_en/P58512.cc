/* Interest rates */
#include <iostream>
#include <cmath>

/*
double pow(double x, int k)
{
  if (k == 0) return 1;

  double y = pow(x, k/2);
  if (k%2 == 0) return y*y;
  return y*y*x;
}
*/

int min_days(double m, double f, double r, int i, int j)
{
  if (i > j) return i;

  int k = (i + j)/2;

  double oak = m + f*k;
  double bank = m*std::pow(r, k);

  if (oak < bank) return min_days(m, f, r, i, k-1);
  return min_days(m, f, r, k+1, j); /* else if (oak > bank) */
  /* return k; (if oak == bank) */
}

int main()
{
  double m, f, r;
  while (std::cin >> m >> f >> r)
  {
    std::cout << min_days(m, f, 1 + r/100, 1, 1e7) << std::endl;
  }
}

/*
Professor Obokaman and Professor Oak go to buy something cheap for lunch. As usual, Prof. Obokaman has no cash at hand, so he asks some coins to Prof. Oak.
“No problem”, says Prof. Oak. “I lend you 5 euros. Since you are a good friend of mine, I will only charge you 1 euro per day until you return the coins to me.”
Prof. Obokaman looks a bit puzzled by this offer, so Prof. Oak adds: “You see, now banks charge a daily interest rate of 0.013368%, right?”
Prof. Obokaman knows that banks charge 5% every year. Since he is a bright mathematician, he has no problems to mentally check that this is indeed true (assuming 365 days per year): 1.00013368365 ≃ 1.05. “Yes, but…” he tries to say.
“Therefore”, Prof. Oak interrupts, “if you wait enough days before returning the coins to me, let’s see … 71589 days or more, to be precise, then my deal is better than the banks’ offer.”
Prof. Obokaman agrees that this reasoning is correct, but he is too polite to say that he will very likely return the coins sooner than that, losing a lot of money…

Input consists of several test cases. Each test case consists of three real
numbers: the amount of money m of the coins generously lent by Prof. Oak, the
fixed amount of money f charged daily to Prof. Obokaman, and the % daily interest
rate r offered by the banks. You can assume 0.1 ≤ m ≤ 1000, 0.1 ≤ f ≤ 1000, and 0.001 ≤ r ≤ 10.

For every test case, print the minimum number of days d that Prof. Obokaman should
wait before returning the money to get a deal that is better than the banks’ offer.
Assume that the test cases have no precision issues, and that every solution d will be between 1 and 10^7.
*/

/*
 * P. oak: 1e/day
 * Bank: 0.013368%/day => 1 + 0.013368/100 => 1.00013368
 *    => (1.00013368)^365 ~= 1.05 (5%/year)
 *
 * When will (5*(1.00013368)^x) > (1*x)?
 *
 * P.oak day 71589 => 71589 euros
 * Bank day 71589 => 5*((1.00013368)^71589) euros ~= 71597.52816 euros
*/
