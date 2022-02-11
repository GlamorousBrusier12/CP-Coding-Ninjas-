#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define m 1000000007
using namespace std;

void dfs(int **edges, int n, bool *visited, int startingVertex, vector<int> &ans)
{
  visited[startingVertex] = true;
  ans.push_back(startingVertex);
  fin(i, 1, n)
  {
    if (edges[startingVertex][i] == 1 && !visited[i] && i != startingVertex)
    {
      dfs(edges, n, visited, i, ans);
    }
  }
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, e;
  cin >> n >> e;
  int **edges = new int *[n + 1];
  fin(i, 0, n + 1)
  {
    edges[i] = new int[n + 1];
    memset(edges[i], 0, sizeof(int) * (n + 1));
  }
  fin(i, 0, e)
  {
    int a, b;
    cin >> a >> b;
    edges[a][b] = edges[b][a] = 1;
  }
  bool *visited = new bool[n + 1];
  memset(visited, false, sizeof(bool) * (n + 1));
  fin(i, 1, n + 1)
  {
    if (!visited[i])
    {
      vector<int> ans;
      dfs(edges, n + 1, visited, i, ans);
      fin(j, 0, ans.size())
      {
        cout << ans[i] << ' ';
      }
      cout << endl;
    }
  }
  cout << endl;
  return 0;
}