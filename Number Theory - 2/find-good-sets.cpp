#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define m 1000000007
using namespace std;
int numGoodSets(int arr[], int n)
{
  int ans = 0;
  return ans;
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
    int arr[n];
    fin(i, 0, n)
    {
      cin >> arr[i];
    }
    int ans = numGoodSets(arr, n);
    cout << ans << endl;
  }
  return 0;
}