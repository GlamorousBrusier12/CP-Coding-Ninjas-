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
bool makeSentence(vector<string> matrix, int n, int m, bool **visited, string s, int ci, int cj)
{
  // cout << s << ' ';
  if (s.size() == 0)
  {
    return true;
  }
  bool ans;
  // visited[ci][cj] = true;
  int arr[8][2] = {
      {0, 1},
      {1, 1},
      {1, 0},
      {1, -1},
      {0, -1},
      {-1, -1},
      {-1, 0},
      {-1, 1}};
  for (int i = 0; i < 8; i++)
  {
    int x = ci + arr[i][0];
    int y = cj + arr[i][1];
    if (isValid(n, m, x, y) && matrix[x][y] == s[0] && !visited[x][y])
    {
      visited[x][y] = true;
      // printf("(%d, %d), size = %d\n", x, y, s.size() - 1);

      bool smallAns = makeSentence(matrix, n, m, visited, s.substr(1), x, y);
      if (smallAns)
      {
        return true;
      }
      visited[x][y] = false;
    }
  }
  return false;
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
    vector<string> matrix(n);
    fin(i, 0, n)
    {
      cin >> matrix[i];
    }
    bool **visited = new bool *[n];
    fin(i, 0, n)
    {
      visited[i] = new bool[m];
      memset(visited[i], false, sizeof(bool) * m);
    }
    bool found = false;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (matrix[i][j] == 'C')
        {
          found = true;
          cout << makeSentence(matrix, n, m, visited, "ODINGNINJA", i, j) << endl;
        }
      }
    }
    if (!found)
    {
      cout << 0 << endl;
    }
  }
  return 0;
}