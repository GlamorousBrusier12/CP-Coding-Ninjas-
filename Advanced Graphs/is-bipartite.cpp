#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
bool bipartite(vector<int> *edges, int n)
{
  unordered_set<int> set[2];
  vector<int> pending;
  set[0].insert(0);
  pending.push_back(0);
  while (pending.size() > 0)
  {
    int currNode = pending.back();
    pending.pop_back();
    int currSet = set[0].count(currNode) != 0 ? 0 : 1;
    fin(i, 0, edges[currNode].size())
    {
      int neighbour = edges[currNode][i];
      // if the neighbour is not in any of the set
      // then include in the opp set
      if (set[0].count(neighbour) == 0 && set[1].count(neighbour) == 0)
      {
        set[1 - currSet].insert(neighbour);
        pending.push_back(neighbour);
      }
      else if (set[currSet].count(neighbour) > 0)
      {
        return false;
      }
    }
  }
  return true;
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
    int m;
    cin >> m;
    vector<int> *edges = new vector<int>[n];
    fin(i, 0, m)
    {
      int a, b;
      cin >> a >> b;
      edges[a].push_back(b), edges[b].push_back(a);
    }
    bool ans = bipartite(edges, n);
    cout << (ans == true ? "yes" : "no") << endl;
  }
  return 0;
}