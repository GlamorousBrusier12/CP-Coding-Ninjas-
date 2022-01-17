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
  bool arr[n + 1];
  // arr[0] = true;
  memset(arr, true, sizeof(arr));
  arr[0] = arr[1] = false;
  fin(i, 2, sqrt(n) + 1)
  {
    if (arr[i] == true)
    {

      for (int j = i; j <= n; j++)
      {
        arr[i * j] = false;
      }
    }
  }
  int count = 0;
  fin(i, 2, n + 1)
  {
    (arr[i] == true) ? count++ : (NULL);
  }
  cout << count << endl;
  return 0;
}