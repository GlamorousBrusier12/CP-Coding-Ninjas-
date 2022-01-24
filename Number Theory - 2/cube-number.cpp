#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define m 1000000007
using namespace std;
int size = 1000000 + 1;
int main()
{
  int t;
  cin >> t;
  bool *seive = new bool[size];
  for (int i = 0; i < size; i++)
  {
    seive[i] = true;
  }
  cout << "done: " << endl;
  seive[0] = false;
  fin(i, 2, 100)
  {
    int currCube = i * i * i;
    for (int j = 1; j * currCube < size + 1; j++)
    {
      seive[j * currCube] = false;
    }
  }
  unordered_map<int, int> ans;
  int pos = 1;
  fin(i, 1, size)
  {
    if (seive[i])
    {
      ans[i] = pos;
      pos++;
    }
  }
  cout << "done: " << ans.size() << endl;
  while (t--)
  {
    int n;
    cin >> n;
    if (ans.count(n) == 0)
    {
      cout << "Not Cube Free" << endl;
    }
    else
    {
      cout << ans.at(n) << endl;
    }
  }
  return 0;
}