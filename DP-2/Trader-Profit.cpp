#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
// 3d array dp[2][size + 1][numTransactions + 1]
int maxProfit_memo_helper(int arr[], int n, int numTransactions, bool is_transaction_running, int ***dp)
{
  int one = (is_transaction_running == true ? 1 : 0);
  if (dp[one][n][numTransactions] != -1)
  {
    return dp[one][n][numTransactions];
  }
  int ans = INT_MIN;
  if (n == 0 || numTransactions == 0)
  {
    return 0;
  }
  // if you ignore
  int smallAns1, smallAns2;
  smallAns1 = maxProfit_memo_helper(arr + 1, n - 1, numTransactions, is_transaction_running, dp);
  if (is_transaction_running)
  {
    // sell the stock
    smallAns2 = maxProfit_memo_helper(arr + 1, n - 1, numTransactions - 1, false, dp) + arr[0];
  }
  else
  {
    // buy the stock
    smallAns2 = maxProfit_memo_helper(arr + 1, n - 1, numTransactions, true, dp) - arr[0];
  }
  ans = max(smallAns1, smallAns2);
  dp[one][n][numTransactions] = ans;
  return ans;
}
int max_profit_memo(int arr[], int n, int numTransactons, bool is_trans)
{
  int ***dp = new int **[2];
  dp[0] = new int *[n + 1];
  dp[1] = new int *[n + 1];
  fin(i, 0, n + 1)
  {
    dp[0][i] = new int[numTransactons + 1];
    dp[1][i] = new int[numTransactons + 1];
    memset(dp[0][i], -1, sizeof(int) * (numTransactons + 1));
    memset(dp[1][i], -1, sizeof(int) * (numTransactons + 1));
  }
  int ans = maxProfit_memo_helper(arr, n, numTransactons, is_trans, dp);
  fin(i, 0, n + 1)
  {
    delete[] dp[0][i];
    delete[] dp[1][i];
  }
  delete[] dp[0];
  delete[] dp[1];
  return ans;
}
int maxProfit_rec(int arr[], int n, int numTransactions, bool is_transaction_running)
{
  int ans = INT_MIN;
  if (n == 0 || numTransactions == 0)
  {
    return 0;
  }
  // if you ignore
  int smallAns1, smallAns2;
  smallAns1 = maxProfit_rec(arr + 1, n - 1, numTransactions, is_transaction_running);
  if (is_transaction_running)
  {
    // sell the stock
    smallAns2 = maxProfit_rec(arr + 1, n - 1, numTransactions - 1, false) + arr[0];
  }
  else
  {
    // buy the stock
    smallAns2 = maxProfit_rec(arr + 1, n - 1, numTransactions, true) - arr[0];
  }
  ans = max(smallAns1, smallAns2);
  return ans;
}
int maxProfit(int arr[], int n, int numTransactions)
{
  int ans = 0;
  return maxProfit_rec(arr, n, numTransactions, false);
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--)
  {
    int numTransactions, n;
    cin >> numTransactions >> n;
    int arr[n];
    fin(i, 0, n)
    {
      cin >> arr[i];
    }
    cout << maxProfit(arr, n, numTransactions) << endl;
    cout << max_profit_memo(arr, n, numTransactions, false) << endl;
  }
  return 0;
}