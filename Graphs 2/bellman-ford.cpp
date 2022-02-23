#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
class edge
{
public:
  int src, dest, wt;
};
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--)
  {
    int v, e, src, dest;
    cin >> v >> e >> src >> dest;
    // printf("hi\n");
    vector<edge> edg(e);
    fin(i, 0, e)
    {
      cin >> edg[i].src >> edg[i].dest >> edg[i].wt;
      // cout << edg[i].src << ' ' << edg[i].dest << ' ' << edg[i].wt << '\n';
    }
    // printf("edges shit done\n");
    int wt[v + 1];
    fin(i, 0, v + 1)
    {
      wt[i] = INT_MAX;
    }
    wt[src] = 0;
    fin(i, 0, v - 1)
    {
      // ith iteration
      fin(j, 0, e)
      {
        edge currEdge = edg[j];
        int u = currEdge.src, v = currEdge.dest, w = currEdge.wt;
        if ((wt[u] != INT_MAX) && wt[v] > wt[u] + w)
        {
          wt[v] = wt[u] + w;
        }
      }
    }
    // cout << (wt[dest] == INT_MAX ? ((int)10e9) : wt[dest]) << endl;
    cout << wt[dest] << endl;
  }

  return 0;
}