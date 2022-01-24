#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define m 1000000007
using namespace std;
vector<pii> primeFactors(int n)
{
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
  vector<pii> ans;
  fin(i, 2, n + 1)
  {
    if (seive[i])
    {
      int k = n;
      int curCount = 0;
      while (k % i == 0)
      {
        curCount++;
        k /= i;
      }
      if (curCount != 0)
      {
        ans.push_back(make_pair(i, curCount));
      }
    }
  }
  // sort(ans.begin(), ans.end());
  return ans;
}
int showFactors(vector<pii> arr)
{
  int ans = 1;
  for (int i = 0; i < arr.size(); i++)
  {
    printf("(%d^%d) ", arr[i].first, arr[i].second);
  }
  cout << endl;
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
    int ans = n * ((n * (n - 1)) / 2 + 1);
    cout << ans << endl;
  }

  return 0;
}