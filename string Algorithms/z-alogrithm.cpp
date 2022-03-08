#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
void buildZarray(string str, int *z)
{
  int l = 0, r = 0, n = str.length();
  fin(i, 1, n)
  {
    if (i > r)
    {
      l = r = i;
      while (r < n && str[r - l] == str[r])
      {
        r++;
      }
      z[i] = r - l;
      r--;
    }
    else
    {
      int k = i - l;
      if (z[k] <= r - i)
      {
        z[i] = z[k];
      }
      else
      {
        l = i;
        while (r < n && str[r - l] == str[r])
        {
          r++;
        }
        z[i] = r - l;
        r--;
      }
    }
  }
}
void SearchPattern(string text, string pattern)
{
  string zString = pattern + "$" + text;
  int n = zString.size();
  int *zArray = new int[n]();
  buildZarray(zString, zArray);
  fin(i, 0, n)
  {
    if (zArray[i] == pattern.size())
    {
      cout << i - (pattern.size() + 1) << endl;
    }
  }
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  string text, pattern;
  cin >> text >> pattern;

  return 0;
}