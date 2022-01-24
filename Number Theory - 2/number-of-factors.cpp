#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define m 1000000007
#define max 1000000 + 1
using namespace std;
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int *seive = new int[max];
  // seive[0] = true;
  memset(seive, 0, sizeof(int) * (max));
  seive[0] = seive[1] = -1;
  fin(i, 2, max)
  {
    if (seive[i] == 0)
    {

      for (int j = 2; i * j <= max; j++)
      {
        seive[i * j]++;
      }
    }
  }
  int count = 0;
  int t;
  cin >> t;
  while (t--)
  {
    int a, b, n;
    cin >> a >> b >> n;
    int ans = 0;
    fin(i, a, b + 1)
    {
      int sa = (seive[i] == 0 ? 1 : seive[i]);
      if (sa == n)
      {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}