#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define m 1000000007
using namespace std;
int findModulo(string s, int mod)
{
  if (s.size() == 0)
  {
    return 0;
  }
  int smallAns = findModulo(s.substr(0, s.size() - 1), mod);
  smallAns = ((smallAns % mod * 10 % mod) % mod + (s[s.size() - 1] - '0')) % mod;
  return smallAns;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--)
  {
    int a;
    string b;
    cin >> a >> b;
    int modulo = findModulo(b, a);
    cout << __gcd(a, modulo) << endl;
  }
  return 0;
}