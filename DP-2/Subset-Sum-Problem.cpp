#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
bool subsetSum(int arr[], int n, int subset_sum)
{
  bool dp[n + 1][subset_sum + 1];
  fin(i, 0, n + 1)
  {
    // if the subset_sum is zero it doesnt matter size it's always true
    dp[i][0] = true;
  }
  fin(i, 1, subset_sum + 1)
  {
    // if the size is zero and the subset_sum is non zero then obviously
    // there is no elements contributing to that sum
    dp[0][i] = false;
  }
  fin(j, 1, subset_sum + 1)
  {
    fin(i, 1, n + 1)
    {
      dp[i][j] = dp[i - 1][j];
      if (!dp[i][j] && j >= arr[n - i])
      {
        dp[i][j] = dp[i - 1][j - arr[n - i]];
      }
    }
  }
  return dp[n][subset_sum];
}
bool subsetSum_xor(int arr[], int n, int subset_sum)
{
  bool dp[2][subset_sum + 1];
  // fin(i, 0, n+1){
  //   // if the subset_sum is zero it doesnt matter size it's always true
  //   dp[i][0] = true;
  // }
  fin(i, 0, subset_sum + 1)
  {
    // if the size is zero and the subset_sum is non zero then obviously
    // there is no elements contributing to that sum
    dp[0][i] = false;
  }
  dp[0][0] = true;
  int flag = 1;
  fin(i, 1, n + 1)
  {
    fin(j, 1, subset_sum + 1)
    {
      dp[flag][j] = dp[flag ^ 1][j];
      if (j >= arr[i - 1])
      {
        dp[flag][j] = dp[flag][j] || dp[flag ^ 1][j - arr[i - 1]];
      }
    }
    flag = flag ^ 1;
  }
  return dp[flag^1][subset_sum];
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n;
    int arr[n];
    fin(i, 0, n)
    {
      cin >> arr[i];
    }
    cin >> k;
    cout << (subsetSum_xor(arr, n, k) == true ? "Yes" : "No") << endl;
  }
  return 0;
}