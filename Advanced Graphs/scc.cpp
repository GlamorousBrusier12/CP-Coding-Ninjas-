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
void dfsT(vector<int> *edges, int currNode, bool *visited, unordered_set<int> *components)
{
  visited[currNode] = true;
  components->insert(currNode);
  fin(i, 0, edges[currNode].size())
  {
    int next = edges[currNode][i];
    if (!visited[next])
    {
      dfsT(edges, next, visited, components);
    }
  }
  // finished->push(currNode);
}
unordered_set<unordered_set<int> *> *getScc(vector<int> *edges, vector<int> *edgesT, int n)
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
  unordered_set<unordered_set<int> *> *stronglyConnectedComp = new unordered_set<unordered_set<int> *>();
  while (!finishedNodes->empty())
  {
    int curr = finishedNodes->top();
    finishedNodes->pop();
    if (!visited[curr])
    {
      unordered_set<int> *smallAns = new unordered_set<int>();
      dfsT(edgesT, curr, visited, smallAns);
      stronglyConnectedComp->insert(smallAns);
    }
  }
  delete[] visited;
  delete finishedNodes;
  return stronglyConnectedComp;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  vector<int> *edges = new vector<int>[n];
  vector<int> *edgesT = new vector<int>[n];
  int m;
  cin >> m;
  fin(i, 0, m)
  {
    int a, b;
    cin >> a >> b;
    edges[a - 1].push_back(b - 1), edgesT[b - 1].push_back(a - 1);
  }
  unordered_set<unordered_set<int> *> *scc = getScc(edges, edgesT, n);
  unordered_set<unordered_set<int> *>::iterator it1 = scc->begin();
  while (it1 != scc->end())
  {
    unordered_set<int> *component = *it1;
    unordered_set<int>::iterator it2 = component->begin();
    while (it2 != component->end())
    {
      cout << *it2 + 1 << ' ';
      it2++;
    }
    cout << endl;
    delete component;
    it1++;
  }
  cout << endl;
  delete scc;
  delete[] edges;
  delete[] edgesT;

  return 0;
}