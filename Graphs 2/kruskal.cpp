#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
class Edge
{
public:
  int v1, v2;
  int wt;
  Edge()
  {
    v1 = v2 = wt = 0;
  }
};
bool comparator(Edge const &e1, Edge const &e2)
{
  return e1.wt < e2.wt;
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
    Edge edges[e];
    fin(i, 0, e)
    {
      cin >> edges[i].v1;
      cin >> edges[i].v2;
      cin >> edges[i].wt;
    }
    sort(edges, edges + e, comparator);
    Edge mst[v - 1];
    int count = 0, parent[e], ans = 0;
    fin(i, 0, v)
    {
      parent[i] = i;
    }
    for (int i = 0; i < e && count < v; i++)
    {
      int p1 = edges[i].v1, p2 = edges[i].v2;
      while (p1 != parent[p1])
      {
        p1 = parent[p1];
      }
      while (p2 != parent[p2])
      {
        p2 = parent[p2];
      }
      if (p1 != p2)
      {
        // cout << "included " << edges[i].wt << ' ';
        ans += edges[i].wt;
        mst[count++] = edges[i];
        parent[p2] = p1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}