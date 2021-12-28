#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    if (n % 4 == 0)
    {
      cout << n << endl;
    }
    if (n % 4 == 1)
    {
      cout << 1 << endl;
    }
    if (n % 4 == 2)
    {
      cout << n + 1 << endl;
    }
    if (n % 4 == 3)
    {
      cout << 0 << endl;
    }
  }
  return 0;
}