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
  int n = s.length(), count = 0, maxLen = 0;
  fin(i, 0, n)
  {
    // odd length substring
    int l = i, r = i, sum = 0;
    while (l >= 0 && r < n && s[l] == s[r])
    {
      if (s[l] == '0')
      {
        l--, r++;
        continue;
      }
      int num = s[l] - '0';
      sum += num;
      if (l != r)
      {
        sum += num;
      }
      if (sum % 3 == 0 && sum != 0)
      {
        count++;
      }
      l--, r++;
    }
    // even length substring
    l = i, r = i + 1, sum = 0;
    while (l >= 0 && r < n && s[l] == s[r])
    {
      if (s[l] == '0')
      {
        l--, r++;
        continue;
      }
      int num = s[l] - '0';
      sum += 2 * num;
      if (sum % 3 == 0 && sum != 0)
      {
        count++;
      }
      l--, r++;
    }
  }
  return count;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  string s;
  cin >> s;
  cout << longestPalindromeSubstring(s) << endl;

  return 0;
}