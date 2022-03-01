#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
int getMinVertex(bool visited[], int n, int weight[])
{
  int minVertex = -1;
  fin(i, 0, n)
  {
    if (visited[i] == false && (minVertex == -1 || weight[i] < weight[minVertex]))
    {
      minVertex = i;
    }
  }
  return minVertex;
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
    int **edges = new int *[v];
    fin(i, 0, v)
    {
      edges[i] = new int[v];
      memset(edges[i], 0, sizeof(int) * v);
    }
    fin(i, 0, e)
    {
      int a, b, wt;
      cin >> a >> b >> wt;
      if (edges[a][b] == 0)
      {

        edges[a][b] = edges[b][a] = wt;
      }
      else
      {
        edges[a][b] = edges[b][a] = min(edges[a][b], wt);
      }
    }
    int parent[v], wt[v];
    fin(i, 0, v)
    {
      parent[i] = -1;
      wt[i] = INT_MAX;
    }
    parent[0] = 0;
    wt[0] = 0;

    bool *visited = new bool[v];
    memset(visited, false, sizeof(bool) * v);
    int visitedCount = 0;
    int minIndex = 0;
    while (visitedCount != v)
    {
      int curIndex = getMinVertex(visited, v, wt);
      int currWt = wt[curIndex];
      visited[curIndex] = true;
      fin(i, 0, v)
      {
        if (visited[i] != true && edges[i][curIndex] > 0 && edges[i][curIndex] < wt[i])
        {
          wt[i] = edges[i][curIndex];
          parent[i] = curIndex;
          // printf("updated %d to %d=>%d\n", i, wt[i], parent[i]);
        }
      }
      visitedCount++;
    }
    int ans = 0;
    fin(i, 1, v)
    {
      ans += edges[i][parent[i]];
      cout << i << ' ' << parent[i] << ' ' << edges[i][parent[i]] << endl;
    }
    cout << ans << endl;
  }

  return 0;
}