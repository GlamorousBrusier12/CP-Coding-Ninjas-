#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
int *dp = new int[1000000 + 1];
int mex(int a, int b, int c)
{
  fin(i, 0, max(a, max(b, c)))
  {
    if (i != a && i != b && i != c)
    {
      return i;
    }
  }
  return max(a, max(b, c)) + 1;
}
int grundy(int n)
{
  if (n == 0 || n == 1)
  {
    return n;
  }
  if (dp[n] != -1)
  {
    return dp[n];
  }
  // if ( n== 2)
  dp[n] = mex(grundy(n / 2), grundy(n / 3), grundy(n / 6));
  return dp[n];
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  memset(dp, -1, sizeof(int) * (1000000 + 1));
  while (t--)
  {
    int n;
    cin >> n;
    cout << grundy(n) << endl;
  }
  return 0;
}