#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define m 1000000007
using namespace std;
void bfs(int **edges, int n, bool *visited, int startingVertex)
{
  queue<int> pendingNodes;
  pendingNodes.push(startingVertex);
  while (!pendingNodes.empty())
  {
    int currentNode = pendingNodes.front();
    pendingNodes.pop();
    if (visited[currentNode])
    {
      continue;
    }
    visited[currentNode] = true;
    fin(i, 0, n)
    {
      if (edges[currentNode][i] == 1 && visited[i] == false)
      {
        pendingNodes.push(i);
      }
    }
  }
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--)
  {
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    fin(i, 0, n)
    {
      edges[i] = new int[n];
      memset(edges[i], 0, sizeof(int) * n);
    }
    fin(i, 0, e)
    {
      int a, b;
      cin >> a >> b;
      edges[a][b] = edges[b][a] = 1;
    }
    bool *visited = new bool[n];
    memset(visited, false, sizeof(bool) * n);
    int ans = 0;
    fin(i, 0, n)
    {
      if (!visited[i])
      {
        ans++;
        bfs(edges, n, visited, i);
      }
    }
    cout << ans << endl;
  }

  return 0;
}