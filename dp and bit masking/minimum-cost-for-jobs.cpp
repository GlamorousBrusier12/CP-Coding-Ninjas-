#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
int minCostI(int cost[4][4], int n)
{
  int dp[(1 << n)];
  fin(i, 0, (1 << n))
  {
    dp[i] = INT_MAX;
  }
  dp[0] = 0;
  fin(mask, 0, (1 << n))
  {
    int temp = mask;
    int numSetBits = 0;
    while (temp > 0)
    {
      if (temp % 2 == 1)
      {
        numSetBits++;
      }
      temp = temp / 2;
    }
    fin(j, 0, n)
    {
      if (!(mask & (1 << j)))
      {
        dp[mask | (1 << j)] = min(dp[mask | (1 << j)], dp[mask] + cost[numSetBits][j]);
      }
    }
  }
  return dp[(1 << n) - 1];
}
int minCost(int cost[4][4], int n, int p, int m, int *dp)
{
  if (p >= n)
  {
    return 0;
  }
  // check if the ans is pre calculated
  if (dp[m] != INT_MAX)
  {
    // if the ans is precalculated then DRY
    return dp[m];
  }
  int ans = INT_MAX;
  fin(i, 0, n)
  {
    // find if the bit is set and if not assign the job to p
    if (!(m & (1 << i)))
    {
      int smallAns = minCost(cost, n, p + 1, m | (1 << i), dp) + cost[p][i];
      ans = min(smallAns, ans);
    }
  }
  // save the ans
  dp[m] = ans;
  return ans;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  // int t;
  // cin >> t;
  // while(t--){

  // }
  int cost[4][4] = {{10, 2, 6, 5},
                    {1, 15, 12, 8},
                    {7, 8, 9, 3},
                    {15, 13, 4, 10}};
  int *dp = new int[1 << 4];
  fin(i, 0, 1 << 4)
  {
    dp[i] = INT_MAX;
  }
  cout << minCost(cost, 4, 0, 0, dp) << endl;
  cout << minCostI(cost, 4) << endl;
  return 0;
}