#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define m 1000000007
using namespace std;
unordered_map<int, int> makePrimeFactors(int n)
{
  int k = n;
  unordered_map<int, int> ans;
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
  for (int i = 2; i <= n && k != 1; i++)
  {
    if (!seive[i])
      continue;
    int curCount = 0;
    while (k % i == 0)
    {
      curCount++;
      k /= i;
    }
    if (curCount != 0)
    {
      ans[i] = (curCount);
    }
  }
  if (k != 1)
  {
    ans[k] = 1;
  }
  return ans;
}
void removePrimeFactors(unordered_map<int, int> &ans, int n)
{
  unordered_map<int, int> newFactors = makePrimeFactors(n);
  for (auto it = newFactors.begin(); it != newFactors.end(); it++)
  {
    if (ans.count(it->first) > 0)
    {
      ans[it->first] -= it->second;
      if (ans[it->first] == 0)
      {
        ans.erase(it->first);
      }
    }
  }
}
void addPrimeFactors(unordered_map<int, int> &ans, int n)
{
  unordered_map<int, int> newFactors = makePrimeFactors(n);
  for (auto it = newFactors.begin(); it != newFactors.end(); it++)
  {
    ans[it->first] += it->second;
  }
}
unordered_map<int, int> makeEmptyPrime(unordered_map<int, int> newFactors)
{
  unordered_map<int, int> res;
  for (auto it = newFactors.begin(); it != newFactors.end(); it++)
  {
    res[it->first] = 0;
  }
  return res;
}
void showPrimeFactors(unordered_map<int, int> ans)
{
  for (auto it = ans.begin(); it != ans.end(); it++)
  {
    printf("(%d^%d), ", it->first, it->second);
  }
  cout << endl;
}
bool isDivisible(unordered_map<int, int> a, unordered_map<int, int> b)
{
  for (auto it = a.begin(); it != a.end(); it++)
  {
    if (a[it->first] < b[it->first])
    {
      return false;
    }
  }
  return true;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  // int t;
  // cin >> t;
  // while (t--)
  // {
  int n, k;
  cin >> n >> k;
  int arr[n];
  fin(i, 0, n)
  {
    cin >> arr[i];
  }
  cout << "intput Done " << endl;
  unordered_map<int, int> vp = makePrimeFactors(k);
  unordered_map<int, int> vc = makeEmptyPrime(vp);
  int ans = 0;
  int i = 0, j = 0;
  for (int i = 0; i < n; i++)
  {
    addPrimeFactors(vc, arr[i]);
    while (j <= i)
    {
      bool isDiv = isDivisible(vc, vp);
      if (!isDiv)
      {
        break;
      }
      ans += n - i;
      removePrimeFactors(vc, arr[j]);
      j++;
    }
  }

  cout << ans << endl;
  // }

  // unordered_map<int, int> vp = makePrimeFactors(234);
  // unordered_map<int, int> vc = makePrimeFactors(234);
  // cout << isDivisible(vc, vp) << isDivisible(vp, vc) << endl;
  return 0;
}