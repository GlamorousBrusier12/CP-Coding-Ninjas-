#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
int smallestSubseq_rec(string s1, string s2)
{
  if (s2.length() == 0)
  {
    return 1;
  }
  else if (s1.length() == 0)
  {
    return 100;
  }
  else
  {
    int ans = smallestSubseq_rec(s1.substr(1), s2);
    int i = 0;
    for (; i < s2.length(); i++)
    {
      if (s1[0] == s2[i])
      {
        break;
      }
    }
    if (i == s2.length())
    {
      return 1;
    }
    int smallAns = smallestSubseq_rec(s1.substr(1), s2.substr(i + 1));
    return min(1 + smallAns, ans);
  }
}
int smallestSubseq_helper(string s1, string s2, int **dp)
{
  if (s2.length() == 0)
  {
    return 1;
  }
  else if (s1.length() == 0)
  {
    return 100;
  }
  if (dp[s1.length()][s2.length()] != -1)
  {
    return dp[s1.length()][s2.length()];
  }
  else
  {
    int ans = smallestSubseq_helper(s1.substr(1), s2, dp);
    int i = 0;
    for (; i < s2.length(); i++)
    {
      if (s1[0] == s2[i])
      {
        break;
      }
    }
    if (i == s2.length())
    {
      return 1;
    }
    int smallAns = smallestSubseq_helper(s1.substr(1), s2.substr(i + 1), dp);
    dp[s1.length()][s2.length()] = min(1 + smallAns, ans);
    return dp[s1.length()][s2.length()];
  }
}
int smallestSubseq_mem(string s1, string s2)
{
  int **dp = new int *[s1.length() + 1];
  fin(i, 0, s1.length() + 1)
  {
    dp[i] = new int[s2.length() + 1];
    memset(dp[i], -1, sizeof(int) * (s2.length() + 1));
  }
  int ans = smallestSubseq_helper(s1, s2, dp);
  fin(i, 0, s1.length() + 1)
  {
    delete[] dp[i];
  }
  delete[] dp;
  return ans;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  string s1, s2;
  cin >> s1 >> s2;
  cout << smallestSubseq_mem(s1, s2) << endl;
  return 0;
}
