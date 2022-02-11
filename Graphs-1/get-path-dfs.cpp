#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define m 1000000007
using namespace std;
vector<int> getPath(int **edges, int n, bool *visited, int sv, int ev)
{
  vector<int> ans;
  visited[sv] = true;
  if (sv == ev)
  {
    ans.push_back(ev);
    return ans;
  }
  fin(i, 0, n)
  {
    if (edges[sv][i] == 1 && !visited[i])
    {
      ans = getPath(edges, n, visited, i, ev);
      if (ans.size() != 0)
      {
        ans.push_back(sv);
        return ans;
      }
    }
  }
  return ans;
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
    int sv, ev;
    cin >> sv >> ev;
    // getpath
    vector<int> ans = getPath(edges, n, visited, sv, ev);
    // cout << ans.size() << endl;
    fin(i, 0, ans.size())
    {
      cout << ans[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}