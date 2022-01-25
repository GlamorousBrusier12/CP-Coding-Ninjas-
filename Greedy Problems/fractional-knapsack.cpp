#include <bits/stdc++.h>
#include <iostream>
#include <iomanip> // std::setprecision
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define pff pair<float, float>
#define pdd pair<double, double>
#define ll long long
#define m 1000000007
using namespace std;
bool sortFun(const pdd &a, const pdd &b)
{
  return a.first / a.second > b.first / b.second;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, maxWt;
  cin >> n >> maxWt;
  vector<pdd> arr(n);
  // first val, second wt
  fin(i, 0, n)
  {
    cin >> arr[i].first >> arr[i].second;
  }
  sort(arr.begin(), arr.end(), sortFun);
  double totalWt, totalVal;
  totalVal = totalWt = 0.0;
  int i = 0;
  while (i < n && totalWt < maxWt)
  {
    if (totalWt + arr[i].second >= maxWt)
    {
      break;
    }
    totalWt += arr[i].second;
    totalVal += arr[i].first;
    i++;
  }
  if (totalWt < maxWt && i < n)
  {
    totalVal = totalVal + (maxWt - totalWt) * (arr[i].first / arr[i].second);
  }
  cout << std::setprecision(6) << fixed << totalVal << endl;
  return 0;
}