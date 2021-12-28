#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define ll long long
#define mod 1000000007
using namespace std;
// set precesion
// cout << fixed << setprecision(6) << ans  <<endl;
double calcDist(double x[], double y[], int i, int j)
{
  double ans;
  ans = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2) * 1.0);
  return ans;
}
void maxHappines(double x[], double y[], double k[], int n)
{
  double dp[n];
  fin(i, 0, n)
  {
    dp[i] = INT_MIN;
  }
  dp[0] = k[0];
  fin(i, 1, n)
  {
    fin(j, 0, i)
    {
      // distance betwen i, j
      double dist = calcDist(x, y, i, j);
      double smallAns = dp[j] + k[i] - dist;
      // printf("(i=%d, j=%d)=>smallAns = %f %f %f %f\n", i, j, dp[j], k[i], dist, smallAns);
      if (smallAns > dp[i])
      {
        dp[i] = smallAns;
      }
    }
  }
  cout << dp[n - 1] << endl;
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
    double x[n], y[n], k[n];
    fin(i, 0, n)
    {
      cin >> x[i] >> y[i] >> k[i];
    }
    cout << fixed << setprecision(6);
    maxHappines(x, y, k, n);
  }
  return 0;
}