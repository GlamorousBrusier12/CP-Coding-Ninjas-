#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
int numSpecialPrimes(int n)
{
  bool seive[n + 1];
  // seive[0] = true;
  memset(seive, true, sizeof(seive));
  seive[0] = seive[1] = false;
  fin(i, 2, n)
  {
    if (seive[i] == true)
    {

      for (int j = 2; i * j <= n; j++)
      {
        seive[i * j] = false;
      }
    }
  }
  int count = 0;
  vector<int> primes;
  fin(i, 2, n + 1)
  {
    if (seive[i])
    {
      count++;
      primes.push_back(i);
    }
  }
  int ans = 0;
  for (int i = 0; i < count - 1; i++)
  {
    int sum = primes[i] + primes[i + 1] + 1;
    if (sum <= n && seive[sum])
    {
      ans++;
      cout << primes[i] << ' ' << primes[i + 1] << ' ' << sum << endl;
    }
  }
  return ans;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    cout << numSpecialPrimes(n) << endl;
  }
  return 0;
}