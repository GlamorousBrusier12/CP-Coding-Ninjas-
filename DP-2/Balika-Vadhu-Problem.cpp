#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
int getAsci(char c)
{
  return (int)c;
}
int maxBlessings(string s1, string s2, int k)
{
  int ans;
  if (k == 0)
  {
    return 0;
  }
  if (s1.length() == 0 || s2.length() == 0)
  {
    return INT_MIN;
  }
  if (s1[0] == s2[0])
  {
    // case - 1 we consider the first character
    int smallAns1 = maxBlessings(s1.substr(1), s2.substr(1), k - 1);
    ans = smallAns1 + getAsci(s1[0]);
    // case - 2 we consider the first character
    int smallAns2 = maxBlessings(s1.substr(1), s2.substr(1), k);
    ans = max(ans, smallAns2);
  }
  else
  {
    int smallAns1 = maxBlessings(s1.substr(1), s2, k);
    int smallAns2 = maxBlessings(s1, s2.substr(1), k);
    ans = max(smallAns1, smallAns2);
  }
  return ans;
}
int maxBlessings_helper(string s1, string s2, int k, int dp[][101][101])
{
  int ans;
  if (k == 0)
  {
    return 0;
  }
  if (s1.length() == 0 || s2.length() == 0)
  {
    return INT_MIN;
  }
  if (dp[k][s1.size()][s2.size()] != -1)
  {
    return dp[k][s1.size()][s2.size()];
  }
  if (s1[0] == s2[0])
  {
    // case - 1 we consider the first character
    int smallAns1 = maxBlessings_helper(s1.substr(1), s2.substr(1), k - 1, dp);
    ans = smallAns1 + getAsci(s1[0]);
    // case - 2 we consider the first character
    int smallAns2 = maxBlessings_helper(s1.substr(1), s2.substr(1), k, dp);
    ans = max(ans, smallAns2);
  }
  else
  {
    int smallAns1 = maxBlessings_helper(s1.substr(1), s2, k, dp);
    int smallAns2 = maxBlessings_helper(s1, s2.substr(1), k, dp);
    ans = max(smallAns1, smallAns2);
  }
  dp[k][s1.size()][s2.size()] = ans;
  return dp[k][s1.size()][s2.size()];
}
int max_memo(string s1, string s2, int k)
{
  int dp[k + 1][101][101];
  memset(dp, -1, sizeof(dp));
  int ans = maxBlessings_helper(s1, s2, k, dp);
  return (ans < 0 ? 0 : ans);
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--)
  {
    string s1, s2;
    int k;
    cin >> s1 >> s2 >> k;
    cout << max_memo(s1, s2, k) << '\n';
  }
  return 0;
}