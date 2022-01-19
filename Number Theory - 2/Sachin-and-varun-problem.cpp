#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
class Tri
{
public:
  ll x, y, ans;
  Tri() {}
  Tri(ll x, ll y, ll ans)
  {
    this->x = x;
    this->y = y;
    this->ans = ans;
  }
};
Tri extended_euclid(ll a, ll b)
{
  if (b == 0)
  {
    Tri ans(1, 0, a);
    return ans;
  }
  // extended euclid algo
  Tri smallAns = extended_euclid(b, a % b);
  ll x, y, ans1;
  x = smallAns.y;
  y = smallAns.x - smallAns.y * (a / b);
  ans1 = smallAns.ans;
  Tri ans2(x, y, ans1);
  return ans2;
}
ll mmInverse(ll a, ll m)
{
  Tri ans = extended_euclid(a, m);
  return (ans.x % m + m) % m;
}
ll numPairs(ll a, ll b, ll d)
{
  ll mInverse = mmInverse(b, a);
  int g = __gcd(a, b);
  if (d % g)
  {
    return 0;
  }
  a /= g, b /= g, d /= g;
  ll y1 = (d % a * mInverse % a);
  ll n = (d / b - y1) / a;
  // cout << "y1 = " << y1 << " a = " << a << " n  = " << n << endl;
  if (d < b * y1)
  {
    return 0;
  }
  return (n + 1);
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--)
  {
    ll a, b, d;
    cin >> a >> b >> d;
    cout << numPairs(a, b, d) << endl;
  }
  return 0;
}