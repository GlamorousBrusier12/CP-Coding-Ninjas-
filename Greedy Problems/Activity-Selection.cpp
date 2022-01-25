#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define m 1000000007
using namespace std;
bool sortFun(const pii &a, const pii &b)
{
  return a.second < b.second;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  vector<pii> arr(n);
  fin(i, 0, n)
  {
    cin >> arr[i].first >> arr[i].second;
  }
  sort(arr.begin(), arr.end(), sortFun);
  int prevEnding = arr[0].second, ans = 1;
  fin(i, 1, n)
  {
    if (arr[i].first >= prevEnding)
    {
      ans++, prevEnding = arr[i].second;
    }
  }
  cout << ans << endl;
  return 0;
}