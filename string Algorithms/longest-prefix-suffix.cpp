#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define m 1000000007
using namespace std;
string longestPrefix_mysolution(string s)
{
  int n = s.size();
  int ans[n];
  int j = 0, i = 1;
  ans[0] = 0;
  for (; i < n; i++)
  {
    if (s[i] == s[j])
    {
      ans[i] = j + 1;
      j++;
    }
    else
    {
      while (j > 0 && s[i] != s[j])
      {
        j = ans[j - 1];
      }
      if (s[i] == s[j])
      {
        ans[i] = j + 1;
        j++;
      }
      else
      {
        ans[i] = 0;
      }
    }
  }
  // cout << ans[n-1] << endl;
  return s.substr(0, ans[n - 1]);
}
string longestPrefix2(string s)
{
  int n = s.size();
  int ans[n];
  int j = 0, i = 1;
  ans[0] = 0;
  while (i < n)
  {
    if (s[i] == s[j])
    {
      ans[i] = j + 1;
      j++;
      i++;
    }
    else
    {
      if (j == 0)
      {
        ans[i] = 0;
        i++;
      }
      else
      {
        j = ans[j - 1];
      }
    }
  }
  // cout << ans[n-1] << endl;
  return s.substr(0, ans[n - 1]);
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    cout << longestPrefix(s) << endl;
  }
  return 0;
}