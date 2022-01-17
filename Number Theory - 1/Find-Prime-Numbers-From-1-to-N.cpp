#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
bool isPrime(int n)
{
  int count = 0;
  for (int i = 1; i * i <= n; i++)

  {
    if (n % i == 0)
    {
      if (i * i == n)
      {
        count += 1;
      }
      else
      {
        count += 2;
      }
    }
  }
  return (count == 2);
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  int count = 0;
  fin(i, 2, t + 1)
  {
    if (isPrime(i))
    {
      count++;
    }
  }
  cout << count << endl;
  return 0;
}