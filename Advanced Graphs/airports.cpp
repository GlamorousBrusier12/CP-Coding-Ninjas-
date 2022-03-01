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
    int n, m, airportCost;
    cin >> n >> m >> airportCost;
    Edge edges[m];
    fin(i, 0, m)
    {
      cin >> edges[i].v1;
      cin >> edges[i].v2;
      cin >> edges[i].wt;
    }

    sort(edges, edges + m, comparator);
    int parent[n + 1];
    fin(i, 0, n + 1)
    {
      parent[i] = i;
    }
    // cout << airportCost << 'a' << endl;
    int numEdges = 0;
    int curr = 0;
    ll totalWt = 0;
    while (curr != m && numEdges != n - 1)
    {
      int p1 = edges[curr].v1, p2 = edges[curr].v2;
      while (p1 != parent[p1])
      {
        p1 = parent[p1];
      }
      while (p2 != parent[p2])
      {
        p2 = parent[p2];
      }
      if (p1 != p2 && airportCost > edges[curr].wt)
      {
        parent[p2] = p1;
        totalWt += edges[curr].wt;
        numEdges++;
      }
      curr++;
    }
    ll ans = (n - numEdges) * 1ll * airportCost + totalWt;
    cout << ans << endl;
  }
  return 0;
}