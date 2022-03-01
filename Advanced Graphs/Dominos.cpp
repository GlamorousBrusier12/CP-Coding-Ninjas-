#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
void dfs(vector<int> *edges, int currNode, bool *visited, stack<int> *finished)
{
  visited[currNode] = true;
  // components->insert(currNode);
  fin(i, 0, edges[currNode].size())
  {
    int next = edges[currNode][i];
    if (!visited[next])
    {
      dfs(edges, next, visited, finished);
    }
  }
  finished->push(currNode);
}
void dfs2(vector<int> *edges, int currNode, bool *visited)
{
  visited[currNode] = true;
  fin(i, 0, edges[currNode].size())
  {
    int next = edges[currNode][i];
    if (!visited[next])
    {
      dfs2(edges, next, visited);
    }
  }
}
void *getScc(vector<int> *edges, int n)
{
  stack<int> *finishedNodes = new stack<int>();
  bool *visited = new bool[n];
  memset(visited, false, sizeof(bool) * n);
  fin(i, 0, n)
  {
    if (!visited[i])
    {
      dfs(edges, i, visited, finishedNodes);
    }
  }

  memset(visited, false, sizeof(bool) * n);
  int ans = 0;
  while (!finishedNodes->empty())
  {
    int curr = finishedNodes->top();
    finishedNodes->pop();
    if (!visited[curr])
    {
      dfs2(edges, curr, visited);
      ans++;
    }
  }
  cout << ans << endl;
  delete[] visited;
  delete finishedNodes;
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
    vector<int> *edges = new vector<int>[n];
    int m;
    cin >> m;
    fin(i, 0, m)
    {
      int a, b;
      cin >> a >> b;
      edges[a - 1].push_back(b - 1);
    }
    getScc(edges, n);

    delete[] edges;
  }
  return 0;
}