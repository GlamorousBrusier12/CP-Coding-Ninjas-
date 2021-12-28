#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define ll long long
#define pii pair<int, int>
#define mod 1000000007
using namespace std;
pii knapsack_i(int *weights, int *values, int n, int max_weight)
{
  pii dp[n + 1][max_weight + 1];
  // value.first = value, value.second = meight
  // fill the first row
  fin(i, 0, n + 1)
  {
    dp[i][0] = make_pair(0, 0);
  }
  // fill the first column
  fin(i, 0, max_weight + 1)
  {
    dp[0][i] = make_pair(0, 0);
  }
  fin(j, 1, max_weight + 1)
  {
    fin(i, 1, n + 1)
    {
      // max value for the knapsack of maxweight j and size i
      pii smallAns1 = dp[i - 1][j];
      if (j - weights[n - i] >= 0 && smallAns1.first < values[n - i] + dp[i - 1][j - weights[n - i]].first)
      {
        smallAns1.first = values[n - i] + dp[i - 1][j - weights[n - i]].first;
        smallAns1.second = weights[n - i] + dp[i - 1][j - weights[n - i]].second;
      }
      dp[i][j] = smallAns1;
    }
  }
  fin(i, 0, n + 1)
  {
    fin(j, 0, max_weight + 1)
    {
      cout << dp[i][j].second << ',' << dp[i][j].first << ' ';
    }
    cout << endl;
  }
  cout << endl;
  return dp[n][max_weight];
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, max_weight;
  cin >> n;
  int weights[n], values[n];
  fin(i, 0, n)
  {
    cin >> weights[i];
  }
  fin(i, 0, n)
  {
    cin >> values[i];
  }
  cin >> max_weight;
  pii ans = knapsack_i(weights, values, n, max_weight);
  cout << ans.second << ' ' << ans.first << endl;
  return 0;
}