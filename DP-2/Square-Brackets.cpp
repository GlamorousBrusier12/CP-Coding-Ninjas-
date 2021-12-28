#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
int numBalbrackets(int op, int cl, int n, bool arr[])
{
  int ans = 0;
  if (op > n || cl > n)
  {
    return 0;
  }
  if (op == cl && cl == n)
  {
    return 1;
  }
  // only open
  if (op == cl || arr[op + cl])
  {
    ans = numBalbrackets(op + 1, cl, n, arr);
  }
  // only close
  else if (op == n)
  {
    ans = numBalbrackets(op, cl + 1, n, arr);
  }
  // both
  else
  {
    ans = numBalbrackets(op + 1, cl, n, arr) + numBalbrackets(op, cl + 1, n, arr);
  }
  return ans;
}
int numBalbrackets_helper(int op, int cl, int n, bool arr[], int **dp)
{
  int ans = 0;
  if (op > n || cl > n)
  {
    return 0;
  }
  if (op == cl && cl == n)
  {
    return 1;
  }
  if (dp[op][cl] != -1)
  {
    return dp[op][cl];
  }
  // only open
  if (op == cl || arr[op + cl])
  {
    ans = numBalbrackets_helper(op + 1, cl, n, arr, dp);
  }
  // only close
  else if (op == n)
  {
    ans = numBalbrackets_helper(op, cl + 1, n, arr, dp);
  }
  // both
  else
  {
    int smallAns1 = numBalbrackets_helper(op + 1, cl, n, arr, dp);
    int smallAns2 = numBalbrackets_helper(op, cl + 1, n, arr, dp);
    ans = (smallAns1 + smallAns2) % mod;
  }
  dp[op][cl] = ans;
  return ans;
}
int numBal_memo(int op, int cl, int n, bool arr[])
{
  int **dp = new int *[n + 1];
  fin(i, 0, n + 1)
  {
    dp[i] = new int[n + 1];
    memset(dp[i], -1, sizeof(int) * (n + 1));
  }
  return numBalbrackets_helper(op, cl, n, arr, dp);
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--)
  {
    int tot, n;
    cin >> tot >> n;
    // cout << tot << ' ' << n << endl;
    bool isop[2 * tot];
    fin(i, 0, 2 * tot)
    {
      isop[i] = false;
    }
    fin(i, 0, n)
    {
      int k;
      cin >> k;
      // cout << k << ' ';
      isop[k - 1] = true;
    }
    cout << numBal_memo(1, 0, tot, isop) << endl;
  }
  return 0;
}