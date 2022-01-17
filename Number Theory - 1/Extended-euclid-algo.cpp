#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
class Tri
{
public:
  int x, y, ans;
  Tri() {}
  Tri(int x, int y, int ans)
  {
    this->x = x;
    this->y = y;
    this->ans = ans;
  }
};
Tri extended_euclid(int a, int b)
{
  if (b == 0)
  {
    Tri ans(1, 0, a);
    return ans;
  }
  // extended euclid algo
  Tri smallAns = extended_euclid(b, a % b);
  int x, y, ans1;
  x = smallAns.y;
  y = smallAns.x - smallAns.y * (a / b);
  ans1 = smallAns.ans;
  Tri ans2(x, y, ans1);
  return ans2;
}
void extended(int a, int b)
{
  Tri ans = extended_euclid(a, b);
  cout << "ans.x : " << ans.x << " ans.y : " << ans.y << endl;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--)
  {
    int a, b;
    cin >> a >> b;
    extended(a, b);
  }
  return 0;
}