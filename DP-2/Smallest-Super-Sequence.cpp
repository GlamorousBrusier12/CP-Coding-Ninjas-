#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
int smallestSuperSeq(string s1, string s2)
{
  int size1 = s1.length();
  int size2 = s2.length();
  if (size1 == 0 || size2 == 0)
  {
    return (size1 == 0 ? size2 : size1);
  }
  if (s1[0] == s2[0])
  {
    return 1 + smallestSuperSeq(s1.substr(1), s2.substr(1));
  }
  else
  {
    int smallAns1 = 1 + smallestSuperSeq(s1, s2.substr(1));
    int smallAns2 = 1 + smallestSuperSeq(s1.substr(1), s2);
    return min(smallAns1, smallAns2);
  }
}
int smallestSuperSeq_helper(string s1, string s2, int dp[][501])
{
  int size1 = s1.length();
  int size2 = s2.length();
  if (size1 == 0 || size2 == 0)
  {
    return (size1 == 0 ? size2 : size1);
  }
  if (dp[size1][size2] != -1)
  {
    return dp[size1][size2];
  }
  int ans;
  if (s1[0] == s2[0])
  {
    ans = 1 + smallestSuperSeq_helper(s1.substr(1), s2.substr(1), dp);
  }
  else
  {
    int smallAns1 = 1 + smallestSuperSeq_helper(s1, s2.substr(1), dp);
    int smallAns2 = 1 + smallestSuperSeq_helper(s1.substr(1), s2, dp);
    ans = min(smallAns1, smallAns2);
  }
  dp[size1][size2] = ans;
  return ans;
}
int smallestSuperSeq_memo(string s1, string s2)
{
  int dp[501][501];
  memset(dp, -1, sizeof(dp));
  return smallestSuperSeq_helper(s1, s2, dp);
}
int smallestSupSeq_i(string s1, string s2)
{
  int dp[s1.length() + 1][s2.length() + 1];
  fin(i, 0, s1.length() + 1)
  {
    dp[0][i] = i;
  }
  fin(i, 0, s2.length() + 1)
  {
    dp[i][0] = i;
  }
  fin(i, 1, s1.length() + 1)
  {
    fin(j, 1, s2.length() + 1)
    {
      if (s1[s1.length() - i] == s2[s2.length() - j])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[s1.length()][s2.length()];
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
    cin >> s1 >> s2;
    // cout << smallestSuperSeq_memo(s1, s2) << endl;
    cout << smallestSupSeq_i(s1, s2) << endl;
  }
  return 0;
}