#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
int num3Cycles(int **edges, int n)
{
  int ans = 0;
  // fin(i, 0, n)
  // {
  //   fin(j, 0, n)
  //   {
  //     cout << edges[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  fin(i, 0, n)
  {
    fin(j, 0, n)
    {
      fin(k, 0, n)
      {
        if (j != k && edges[i][j] == 1 && edges[i][k] == 1 && edges[j][k] == 1)
        {
          // cout << i + 1 << j + 1 << k + 1 << ' ';
          ans++;
        }
      }
    }
  }
  return ans / 6;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  int m;
  cin >> m;
  int **edges = new int *[n];
  fin(i, 0, n)
  {
    edges[i] = new int[n];
    memset(edges[i], 0, sizeof(int) * n);
  }
  vector<int> qrr(m), rrr(m);
  fin(i, 0, m)
  {
    cin >> qrr[i];
  }
  fin(i, 0, m)
  {
    cin >> rrr[i];
  }
  fin(i, 0, m)
  {
    int a = qrr[i], b = rrr[i];
    edges[a - 1][b - 1] = edges[b - 1][a - 1] = 1;
  }
  cout << num3Cycles(edges, n) << endl;
  return 0;
}