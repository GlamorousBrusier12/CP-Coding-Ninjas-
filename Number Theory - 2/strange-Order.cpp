#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define m 1000000007
using namespace std;
vector<pii> primeFactors(int n)
{
  bool seive[n + 1];
  memset(seive, true, sizeof(seive));
  seive[0] = seive[1] = false;
  fin(i, 2, n)
  {
    if (seive[i] == true)
    {

      for (int j = 2; i * j <= n; j++)
      {
        seive[i * j] = false;
      }
    }
  }
  vector<pii> ans;
  fin(i, 2, n + 1)
  {
    if (seive[i])
    {
      int k = n;
      int curCount = 0;
      while (k % i == 0)
      {
        curCount++;
        k /= i;
      }
      if (curCount != 0)
      {
        ans.push_back(make_pair(i, curCount));
      }
    }
  }
  sort(ans.begin(), ans.end());
  return ans;
}
bool checkGcd(vector<pii> num1, vector<pii> num2)
{
  int i = 0, j = 0;
  while (i < num1.size() && j < num2.size())
  {
    if (num1[i].first == num2[j].first)
    {
      return true;
    }
    else if (num1[i].first > num2[j].first)
    {
      j++;
    }
    else
    {
      i++;
    }
  }
  return false;
}
int showFactors(vector<pii> arr)
{
  int ans = 1;
  for (int i = 0; i < arr.size(); i++)
  {
    printf("(%d^%d) ", arr[i].first, arr[i].second);
  }
  cout << endl;
  return ans;
}
int numberFromFactors(vector<pii> arr)
{
  int ans = 1;
  for (int i = 0; i < arr.size(); i++)
  {
    int k = pow(arr[i].first, arr[i].second);
    // cout << arr[i].first << ' ' << arr[i].second << endl;
    // cout << ans << ' ' << k << endl;
    ans *= k;
  }
  return ans;
}
int main()
{

  int n = 10;
  // cin >> n;
  vector<vector<pii>> arr;
  fin(i, 1, n + 1)
  {
    arr.push_back(primeFactors(i));
  }
  // cout << 1 << endl;
  vector<int> ans;
  auto it2 = arr.end() - 1;
  int num = numberFromFactors(*it2);
  // cout << num << endl;
  ans.push_back(num);
  bool isAvail[n + 1];
  showFactors(*it2);
  memset(isAvail, true, sizeof(isAvail));
  // for (auto it = arr.end() - 2; it >= arr.begin(); it--)
  for (int i = arr.size() - 2; i >= 0; i--)
  {
    bool push;
    push = checkGcd(arr[i], *it2);
    int a = numberFromFactors(arr[i]);
    cout << a << (push ? "yes" : "no") << endl;
    showFactors(arr[i]);
    if (push)
    {
      ans.push_back(a);
      arr.erase(arr.begin() + i - 1);
      cout << a << endl;
    }
  }
  // }
  // showFactors(*it2);
  // arr.erase(it2);
  fin(i, 0, ans.size())
  {
    cout << ans[i] << ' ';
  }
  cout << endl;
  cout << arr.size() << endl;
  // vector<pii> one = primeFactors(1000);
  // cout << showFactors(one) << endl;
  // cout << numberFromFactors(one) << endl;
  // cout << (checkGcd(one, two) ? "yes" : "no") << endl;
  return 0;
}