#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
int *longestPrefix_mysolution(string s)
{
  int n = s.size();
  int *ans = new int[n];
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
  return ans;
}
bool kmp(string s1, string s2)
{
  int *pfs = longestPrefix_mysolution(s2);
  int i = 0, j = 0, n = s1.size(), m = s2.size();
  while (i < n && j < m)
  {
    // printf("(%d, %d)\n", i, j);
    if (s1[i] == s2[j])
    {
      i++, j++;
    }
    else
    {
      if (j == 0)
      {
        i++;
      }
      else
      {
        j = pfs[j - 1];
      }
    }
  }
  return (j == m);
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
    cin >> s2 >> s1;
    cout << (kmp(s1, s2) ? "Yes" : "No") << endl;
  }
  return 0;
}