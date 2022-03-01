#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
void bfs(vector<int> *edges, int n)
{
  int src = 0, dest = n - 1;
  bool *visited = new bool[n];
  memset(visited, false, sizeof(bool) * n);
  queue<int> pendingNodes;
  pendingNodes.push(src);
  int *level = new int[n];
  level[0] = 0;
  while (!pendingNodes.empty())
  {
    int curr = pendingNodes.front();
    pendingNodes.pop();
    visited[curr] = true;
    fin(i, 0, edges[curr].size())
    {
      if (!visited[edges[curr][i]])
      {
        pendingNodes.push(edges[curr][i]);
        level[edges[curr][i]] = level[curr] + 1;
        if (edges[curr][i] == dest)
        {
          cout << level[edges[curr][i]] << endl;
          return;
        }
      }
    }
  }
  return;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--)
  {
    int v, e;
    cin >> v >> e;
    vector<int> *edges = new vector<int>[v];
    fin(i, 0, e)
    {
      int a, b, wt = 1;
      cin >> a >> b;
      a--, b--;
      edges[a].push_back(b);
      edges[b].push_back(a);
    }
    bfs(edges, v);
  }

  return 0;
}