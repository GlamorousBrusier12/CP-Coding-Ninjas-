#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
bool isValid(int n, int m, int ci, int cj)
{
  return (ci >= 0 && cj >= 0 && ci < n && cj < m);
}
int dfs(int **edges, int n, int ci, int cj, bool **visited, bool **canstart)
{
  int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}, ans = 1;

  fin(i, 0, 4)
  {
    int x = ci + dir[i][0];
    int y = cj + dir[i][1];
    if (isValid(n, n, x, y) && edges[x][y] == 1 && !visited[x][y])
    {
      // printf("(%d, %d)=>%d\n", x, y, edges[x][y]);
      visited[x][y] = true;
      canstart[ci][cj] = true;
      int smallAns = dfs(edges, n, x, y, visited, canstart);
      // dfs(edges, n, x, y, visited, canstart);
      // visited[x][y] = false;
      ans = smallAns + ans;
    }
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
    int n;
    cin >> n;
    int **cake = new int *[n];
    bool **visited = new bool *[n];
    bool **check = new bool *[n];
    fin(i, 0, n)
    {
      cake[i] = new int[n];
      visited[i] = new bool[n];
      check[i] = new bool[n];
      string s;
      cin >> s;
      fin(j, 0, n)
      {
        cake[i][j] = s[j] - '0';
        visited[i][j] = false;
        check[i][j] = false;
      }
    }
    // fin(i, 0, n)
    // {
    //   fin(j, 0, n)
    //   {
    //     cout << cake[i][j] << ' ';
    //   }
    //   cout << endl;
    // }
    // cout << endl;
    int ans = 0;
    fin(i, 0, n)
    {
      fin(j, 0, n)
      {
        if (cake[i][j] == 1 && !check[i][j])
        {
          // cout << "HI" << i << j << ' ';
          check[i][j] = visited[i][j] = true;
          int smallAns = dfs(cake, n, i, j, visited, check);
          // cout << "sA: " << smallAns << ' ';
          ans = max(ans, smallAns);
        }
      }
    }
    cout << ans << endl;
    // int maxAns = dfs();
  }
  return 0;
}