#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
int num_super_prime(int n)
{
  // build a seive
  bool seive[n + 1];
  // memset(seive, 1, sizeof(seive));
  fin(i, 0, n + 1)
  {
    seive[i] = true;
  }
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
  // fin(i, 2, n + 1)
  // {
  //   cout << i << (seive[i] == true ? "p" : "np") << ' ';
  // }
  // cout << endl;
  // cout << "HAHA" << endl;
  int numberSeive[n + 1];
  fin(i, 0, n + 1)
  {
    numberSeive[i] = 0;
  }
  // memset(numberSeive, 0, sizeof(numberSeive));
  for (int i = 2; i < n + 1; i++)
  {
    if (!seive[i])
      continue;
    for (int j = 2; i * j <= n; j++)
    {
      numberSeive[i * j]++;
    }
  }
  // fin(i, 0, n + 1)
  // {
  //   cout << numberSeive[i] << ' ';
  // }
  // cout << endl;
  int count = 0;
  fin(i, 0, n + 1)
  {
    (numberSeive[i] == 2 ? count++ : NULL);
  }
  return count;
}
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
    cout << num_super_prime(n) << endl;
  }
  return 0;
}