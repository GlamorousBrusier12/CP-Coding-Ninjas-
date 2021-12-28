#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
int maxSubArray(int arr[], int n)
{
  if (n == 0)
    return 0;
  int currentSum = 0, maxSum = 0;
  int maxi = arr[0];
  for (int i = 0; i < n; i++)
  {
    currentSum += arr[i];
    maxi = max(maxi, arr[i]);
    if (currentSum < 0)
    {
      currentSum = 0;
    }
    else if (currentSum > maxSum)
    {
      maxSum = currentSum;
    }
  }
  if (maxSum == 0)
  {
    return maxi;
  }
  return maxSum;
}
int maxSumRectangle(int **arr, int n, int m)
{
  int sum[n][m];
  fin(i, 0, n)
  {
    sum[i][0] = arr[i][0];
  }
  fin(i, 0, n)
  {
    fin(j, 1, m)
    {
      sum[i][j] = sum[i][j - 1] + arr[i][j];
    }
  }
  int maxi = INT_MIN;
  // fin(i, 0, n)
  // {
  //   fin(j, 0, m)
  //   {
  //     cout << sum[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  fin(i, 0, m)
  {
    fin(j, i, m)
    {
      int sum_array[n];
      // filling the sum array
      fin(k, 0, n)
      {
        sum_array[k] = sum[k][j] - sum[k][i] + arr[k][i];
      }
      int ans = maxSubArray(sum_array, n);
      maxi = max(maxi, ans);
    }
  }

  return maxi;
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
    cout << maxSumRectangle(arr, n, m) << endl;
  }
  return 0;
}