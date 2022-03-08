#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
int longestPalindromeSubstring(string s)
{
  int n = s.length(), maxLen = 0;
  fin(i, 1, n)
  {
    // odd length substring
    int l = i - 1, r = i + 1;
    while (l >= 0 && r < n && s[l] == s[r])
    {
      maxLen = max(maxLen, r - l + 1);
      l--, r++;
    }
    l = i, r = i + 1;
    while (l >= 0 && r < n && s[l] == s[r])
    {
      maxLen = max(maxLen, r - l + 1);
      l--, r++;
    }
  }
  return maxLen;
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
    cout << longestPalindromeSubstring(s) << endl;
  }
  return 0;
}