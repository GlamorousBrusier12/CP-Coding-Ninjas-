#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define m 1000000007
using namespace std;
int numPower(int num, int prime)
{
  int ans = 0, p = prime;
  while (num / p != 0)
  {
    ans += num / p;
    // num = num / p;
    p = p * prime;
  }
  return ans;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t = 0;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    bool seive[n + 1];
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
    int ans = 1;
    for (int i = 0; i < n + 1; i++)
    {
      if (seive[i])
      {
        int smallAns = numPower(n, i);
        ans = (1ll * ans % m * (smallAns + 1) % m) % m;
      }
    }
    cout << ans << endl;
  }
  return 0;
}