#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
bool inLimit(int n, int m, int i, int j){
  if (i >= 0 && j >= 0 && i < n && j < m)
  {
    return true;
  }
  return false;
}
int minimumFare_xor(int **arr, int n, int m)
{
  int dp[2][m];
  int flag = 1;
  fin(i, 0, m)
  {
    dp[flag][i] = arr[n - 1][i];
  }
  flag ^= 1;
  fde(i, n - 2)
  {
    fin(j, 0, m)
    {
      int smallAns = INT_MAX;
      if(inLimit(n, m, i+1, j-1)){
        smallAns = min(smallAns, dp[flag^1][j-1]);
      }
      if(inLimit(n, m, i+1, j)){
        smallAns = min(smallAns, dp[flag^1][j]);
      }
      if(inLimit(n, m, i+1, j+1)){
        smallAns = min(smallAns, dp[flag^1][j+1]);
      }
      //  min(getElement(dp, n, m, i + 1, j - 1), min(getElement(dp, n, m, i + 1, j), getElement(dp, n, m, i + 1, j + 1)));
      dp[flag][j] = smallAns + arr[i][j];
    }
    flag = flag ^ 1;
  }
  int ans = dp[flag^1][0];
  fin(i, 1, m)
  {
    ans = min(ans, dp[flag^1][i]);
  }
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
    int n, m;
    cin >> n >> m;
    int **arr = new int *[n];
    fin(i, 0, n)
    {
      arr[i] = new int[m];
      fin(j, 0, m)
      {
        cin >> arr[i][j];
      }
    }
    cout << minimumFare_xor(arr, n, m) << endl;
  }
  return 0;
}