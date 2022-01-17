#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
int candies(int like[][20], int n, int person, int mask, int *dp)
{
  if (person >= n)
  {
    return 1;
  }
  if (dp[mask] != 0)
  {
    return dp[mask];
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (!(mask & (1 << i)) && like[person][i])
    {
      ans += candies(like, n, person + 1, mask | (1 << i), dp);
    }
  }
  dp[mask] = ans;
  return ans;
}
long long solve(int like[][20], int n)
{
  int *dp = new int[1 << n];
  for (int i = 0; i < (1 << n); i++)
  {
    dp[i] = 0;
  }
  int ans = candies(like, n, 0, 0, dp);
  delete[] dp;
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
    int arr[20][20];
    fin(i, 0, n)
    {
      fin(j, 0, n)
      {
        cin >> arr[i][j];
      }
    }
    cout << solve(arr, n) << endl;
  }
  return 0;
}