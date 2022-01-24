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
  int n;
  cin >> n;
  bool seive[n + 1];
  memset(seive, true, sizeof(seive));
  seive[0] = seive[1] = false;
  fin(i, 2, n)
  {
    if (seive[i] == true)
    {

      for (int j = 2; i * j <= n; j++)
      {
        seive[i * j] = false;
      }
    }
  }
  int count = 0;
  fin(i, 2, n + 1)
  {
    (seive[i] == true) ? count++ : (NULL);
  }
  cout << count << endl;
  return 0;
}