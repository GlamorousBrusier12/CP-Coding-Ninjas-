#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define m 1000000007
using namespace std;
bool checkPrime(int n)
{
  int count = 1;
  for (int i = 2; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      if (i * i == n)
      {
        count += 1;
        // return false;
      }
      else
      {
        count += 2;
      }
    }
  }
  return count == 2;
}
int getPrimes(int n)
{
  int seive[n + 1];
  fin(i, 2, n + 1)
  {
    seive[i] = i;
  }
  fin(i, 2, n + 1)
  {
    if (seive[i] == i)
    {
      // seive[i].numerator--;
      seive[i]--;
      for (int j = 2; i * j <= n; j++)
      {
        seive[i * j] = (seive[i * j] * (i - 1)) / i;
      }
    }
  }
  return seive[n];
}
int getPrimes_updated(int n)
{
  int ans = n;
  for (int i = 2; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      // ans = (ans * (i - 1)) / i;
      while (n % i == 0)
      {
        n = n / i;
      }
      ans = ans - ans / i;
    }
  }
  if (n > 1)
  {
    // a prime number is left and now we remove
    //  the multiples of that prime number
    ans = ans - ans / n;
  }
  return ans;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  // fin(i, 2, 100)
  // {
  //   if (checkPrime(i))
  //     cout << i << endl;
  // }
  while (t--)
  {
    int n;
    cin >> n;
    cout << getPrimes_updated(n) << endl;
  }
  return 0;
}