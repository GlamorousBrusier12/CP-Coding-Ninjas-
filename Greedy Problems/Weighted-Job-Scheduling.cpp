#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define m 1000000007
using namespace std;
class three
{
public:
  int st, et, profit;
};
bool sortComparator(const three &a, const three &b)
{
  return a.et < b.et;
}
int bs(vector<three> &arr, int si, int ei, int x)
{
  int ans = -1;
  while (si <= ei)
  {
    int mid = si + (ei - si) / 2;
    if (arr[mid].et <= x)
    {
      ans = mid;
      si = mid + 1;
    }
    else
    {
      ei = mid - 1;
    }
  }
  return ans;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  vector<three> arr(n);
  fin(i, 0, n)
  {
    cin >> arr[i].st >> arr[i].et >> arr[i].profit;
  }
  sort(arr.begin(), arr.end(), sortComparator);
  int ans[n];
  fin(i, 0, n)
  {
    ans[i] = arr[i].profit;
  }
  fin(i, 1, n)
  {

    int latestNonConflicting = bs(arr, 0, i - 1, arr[i].st);
    if (latestNonConflicting != -1)
    {
      ans[i] = max(ans[latestNonConflicting] + arr[i].profit, ans[i]);
    }
    ans[i] = max(ans[i], ans[i - 1]);
  }
  int maxi = ans[n - 1];
  cout << maxi << endl;
  return 0;
}