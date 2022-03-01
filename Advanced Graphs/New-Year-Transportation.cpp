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
    cin >> n;
    vector<int> *edges = new vector<int>[n];
    fin(i, 0, n - 1)
    {
      int a;
      cin >> a;
      edges[i].push_back(i + a);
    }
    unordered_set<unordered_set<int> *> *connectedComponents = getConnectedComponents(edges, n);
    unordered_set<unordered_set<int> *>::iterator it1 = connectedComponents->begin();
    unordered_set<int> *startingSet;
    int maxPrize = INT_MIN;
    while (it1 != connectedComponents->end())
    {
      unordered_set<int> *group = *it1;
      // unordered_set<int>::iterator it2 = group->begin();
      if (group->find(0) != group->end())
      {
        startingSet = group;
        break;
      }
      it1++;
    }
    cin >> m;
    fin(i, 0, m)
    {
      int dest;
      cin >> dest;
      cout << (startingSet->find(dest - 1) != startingSet->end() ? "yes" : "no") << endl;
    }
  }
  return 0;
}