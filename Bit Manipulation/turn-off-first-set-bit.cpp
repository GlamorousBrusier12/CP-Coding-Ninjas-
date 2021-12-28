#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int k = n & ~(n - 1);
    int a = (1 << (int)log2(k));
    a = n & ~a;
    cout << a << endl;
  }
  return 0;
}