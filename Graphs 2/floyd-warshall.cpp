#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
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
    int **edges = new int *[v + 1];
    fin(i, 0, v + 1)
    {
      edges[i] = new int[v + 1];
      fin(j, 0, v + 1)
      {
        edges[i][j] = INT_MAX;
      }
    }
    fin(i, 0, v + 1)
    {
      edges[i][i] = 0;
    }
    fin(i, 0, e)
    {
      int src, dest, wt;
      cin >> src >> dest >> wt;
      if (edges[src][dest] == INT_MAX)
      {

        edges[src][dest] = edges[dest][src] = wt;
      }
      else
      {
        edges[src][dest] = edges[dest][src] = min(edges[src][dest], wt);
      }
    }
    fin(k, 1, v + 1)
    {
      int mid = k;
      fin(i, 0, v + 1)
      {
        fin(j, 0, v + 1)
        {
          if (edges[i][mid] == INT_MAX || edges[mid][j] == INT_MAX)
          {
            continue;
          }
          if (mid != i && mid != j && i != j)
          {
            if (edges[i][j] > edges[i][mid] + edges[mid][j])
            {
              edges[i][j] = edges[i][mid] + edges[mid][j];
            }
          }
        }
      }
    }
    int q;
    cin >> q;
    while (q--)
    {
      int src, dest;
      cin >> src >> dest;
      cout << (edges[src][dest] == INT_MAX ? 1000000000 : edges[src][dest]) << endl;
    }
  }

  return 0;
}