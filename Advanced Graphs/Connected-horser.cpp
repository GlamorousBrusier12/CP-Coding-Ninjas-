#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
bool isValid(int ci, int cj, int n, int m)
{
  return (ci >= 0 && cj >= 0 && ci < n && cj < m);
}
struct hashFunction
{
  size_t operator()(const pair<int, int> &x) const
  {
    return x.first ^ x.second;
  }
};
void dfs(int **edges, int ci, int cj, bool **visited, unordered_set<pii, hashFunction> *components, int n, int m)
{
  visited[ci][cj] = true;
  components->insert(make_pair(ci, cj));
  int arr[8][2] = {{-1, 2},
                   {1, 2},
                   {2, -1},
                   {2, 1},
                   {-1, -2},
                   {1, -2},
                   {-2, -1},
                   {-2, 1}};
  fin(i, 0, 8)
  {
    int x = ci + arr[i][0];
    int y = cj + arr[i][1];
    if (isValid(x, y, n, m) && !visited[x][y] && edges[x][y] == 1)
    {
      dfs(edges, x, y, visited, components, n, m);
    }
  }
}
ll factorial(ll n)
{
  return (n == 1 || n == 0) ? 1 : (factorial(n - 1) * n) % mod;
}
unordered_set<unordered_set<pii, hashFunction> *> *getConnectedComponents(int **edges, int n, int m)
{
  bool **visited = new bool *[n];
  fin(i, 0, n)
  {
    visited[i] = new bool[m];
    memset(visited[i], false, sizeof(bool) * m);
  }
  int ans = 1;
  unordered_set<unordered_set<pii, hashFunction> *> *output = new unordered_set<unordered_set<pii, hashFunction> *>();
  fin(i, 0, n)
  {
    fin(j, 0, m)
    {
      if (!visited[i][j] && edges[i][j] == 1)
      {
        unordered_set<pii, hashFunction> *smallAns = new unordered_set<pii, hashFunction>();
        dfs(edges, i, j, visited, smallAns, n, m);
        output->insert(smallAns);
      }
    }
  }
  // cout << ans << endl;
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
    int n, m, numHoreses;
    cin >> n >> m >> numHoreses;
    int **edges = new int *[n];
    fin(i, 0, n)
    {
      edges[i] = new int[m];
      memset(edges[i], 0, sizeof(m));
    }
    fin(i, 0, numHoreses)
    {
      int x, y;
      cin >> x >> y;
      edges[x - 1][y - 1] = 1;
    }
    unordered_set<unordered_set<pii, hashFunction> *> *connnectedComponents = getConnectedComponents(edges, n, m);
    unordered_set<unordered_set<pii, hashFunction> *>::iterator it1 = connnectedComponents->begin();
    ll ans = 1;
    while (it1 != connnectedComponents->end())
    {
      unordered_set<pii, hashFunction> *component = *it1;
      ll small = factorial(component->size());
      ans = ((1ll * ans) * small) % mod;
      // cout << "small: " << small << ' ';
      // unordered_set<pii, hashFunction>::iterator it2 = component->begin();
      // while (it2 != component->end())
      // {
      //   pii curr = *it2;
      //   cout << '(' << curr.first << ',' << curr.second << ") ";
      //   it2++;
      // }
      // cout << endl;
      it1++;
    }
    cout << ans << endl;
  }
  return 0;
}