#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
// arr[i].first = pilot sal, arr[i].second = ass pilot sal
int lower_expenses_helper(pii arr[], int n, int diff, int **dp)
{
  if (n == 0)
  {
    return 0;
  }
  if (dp[n][diff] != -1)
  {
    return dp[n][diff];
  }
  int ans = INT_MAX;
  if (diff == 0)
  {
    // only as a assistant
    int smallAns1 = lower_expenses_helper(arr + 1, n - 1, 1, dp) + arr[0].second;
    ans = min(ans, smallAns1);
  }
  else if (diff == n)
  {
    // only as a pilot
    int smallAns1 = lower_expenses_helper(arr + 1, n - 1, diff - 1, dp) + arr[0].first;
    ans = min(ans, smallAns1);
  }
  else
  {
    // or as an pilot
    int smallAns1 = lower_expenses_helper(arr + 1, n - 1, diff - 1, dp) + arr[0].first;
    // either as an assistant
    int smallAns2 = lower_expenses_helper(arr + 1, n - 1, diff + 1, dp) + arr[0].second;
    ans = min(smallAns1, smallAns2);
  }
  dp[n][diff] = ans;
  return ans;
}
int lower_exp_memo(pii arr[], int n)
{
  int **dp = new int *[n + 1];
  fin(i, 0, n + 1)
  {
    dp[i] = new int[(n / 2) + 1];
    memset(dp[i], -1, sizeof(int) * ((n / 2) + 1));
  }
  int ans = lower_expenses_helper(arr, n, 0, dp);
  fin(i, 0, n + 1)
  {
    delete[] dp[i];
  }
  delete[] dp;
  return ans;
}
int lower_expenses_rec_2(pii arr[], int n, int diff)
{
  if (n == 0)
  {
    return 0;
  }
  int ans = INT_MAX;
  if (diff == 0)
  {
    // only as a assistant
    int smallAns1 = lower_expenses_rec_2(arr + 1, n - 1, 1) + arr[0].second;
    ans = min(ans, smallAns1);
  }
  else if (diff == n)
  {
    // only as a pilot
    int smallAns1 = lower_expenses_rec_2(arr + 1, n - 1, diff - 1) + arr[0].first;
    ans = min(ans, smallAns1);
  }
  else
  {
    // or as an pilot
    int smallAns1 = lower_expenses_rec_2(arr + 1, n - 1, diff - 1) + arr[0].first;
    // either as an assistant
    int smallAns2 = lower_expenses_rec_2(arr + 1, n - 1, diff + 1) + arr[0].second;
    ans = min(smallAns1, smallAns2);
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
    pii arr[n];
    fin(i, 0, n)
    {
      cin >> arr[i].first;
      cin >> arr[i].second;
    }
    // fin(i, 0, n + 1)
    // {
    //   cout << arr[i].first << ' ';
    //   cout << arr[i].second << '\n';
    // }
    int ans = lower_exp_memo(arr, n);
    int ans1 = lower_expenses_rec_2(arr, n, 0);
    cout << ans << endl;
    cout << ans1 << endl;
  }
  return 0;
}