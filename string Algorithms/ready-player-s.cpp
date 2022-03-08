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
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, m, k;
  cin >> n >> m >> k;
  string text, pattern, word;
  cin >> text >> word;
  pattern = word.substr(0, k);
  cout << pattern << endl;
  string Zsentence = pattern + "$" + text;
  int num = Zsentence.size();
  int *z = new int[num];
  buildZarray(Zsentence, z);
  int count = 0;
  z[0] = 0;
  fin(i, 0, num)
  {
    cout << z[i] << ' ';
    if (z[i] == k)
    {
      count++;
    }
  }
  cout << count << endl;
  return 0;
}