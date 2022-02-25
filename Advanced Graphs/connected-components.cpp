#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
void dfs(vector<int> *edges, int currNode, bool *visited, unordered_set<int> *components)
{
  visited[currNode] = true;
  components->insert(currNode);
  fin(i, 0, edges[currNode].size())
  {
    int next = edges[currNode][i];
    if (!visited[next])
    {
      dfs(edges, next, visited, components);
    }
  }
}
unordered_set<unordered_set<int> *> *getConnectedComponents(vector<int> *edges, int n)
{
  bool *visited = new bool[n];
  memset(visited, false, sizeof(bool) * n);
  unordered_set<unordered_set<int> *> *output = new unordered_set<unordered_set<int> *>();
  fin(i, 0, n)
  {
    if (!visited[i])
    {
      unordered_set<int> *smallAns = new unordered_set<int>();
      dfs(edges, i, visited, smallAns);
      output->insert(smallAns);
    }
  }
  return output;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--)
  {
    int n, m;
    cin >> n >> m;
    vector<int> *edges = new vector<int>[n];
    fin(i, 0, m)
    {
      int a, b;
      cin >> a >> b;
      edges[a - 1].push_back(b - 1);
      edges[b - 1].push_back(a - 1);
    }
    unordered_set<unordered_set<int> *> *connectedComponents = getConnectedComponents(edges, n);
    unordered_set<unordered_set<int> *>::iterator it1 = connectedComponents->begin();
    while (it1 != connectedComponents->end())
    {
      unordered_set<int> *component = *it1;
      unordered_set<int>::iterator it2 = component->begin();
      while (it2 != component->end())
      {
        cout << *it2 + 1 << ' ';
        it2++;
      }
      cout << endl;
      it1++;
    }
    cout << endl;
  }
  return 0;
}