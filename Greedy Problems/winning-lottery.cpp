#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define m 1000000007
using namespace std;
void giveNum(int sum, int k)
{
  // int firstDigit = 1;
  sum--;
  int arr[k];
  int i = k - 1;
  while (sum >= 9 && i > 0)
  {
    arr[i] = 9;
    sum -= 9;
    i--;
  }
  if (i != 0 && sum > 0)
  {
    arr[i] = sum;
    sum = 0;
    i--;
  }
  while (i > 0 && sum == 0)
  {
    arr[i] = 0;
    i--;
  }
  arr[0] = sum != 0 ? 1 + sum : 1;
  fin(i, 0, k)
  {
    cout << arr[i];
  }
  cout << endl;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--)
  {
    int sum, d;
    cin >> sum >> d;
    giveNum(sum, d);
  }
  return 0;
}