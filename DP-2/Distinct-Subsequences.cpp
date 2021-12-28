#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
#define m 1000000007
using namespace std;
ll distSubseq_old(string s)
{
  ll freq[26];
  memset(freq, -1, sizeof(freq));
  // fin(i, 0, 26)
  // {
  //   cout << freq[i] << ' ';
  // }
  // cout << endl;
  ll dp[s.length() + 1];
  dp[0] = 1;
  // freq[s[0] - 'A'] = 0;
  fin(i, 1, s.length() + 1)
  {
    // cout << s[i] - 'A' << ' ';
    if (freq[s[i - 1] - 'A'] == -1)
    {
      dp[i] = (2 * dp[i - 1]) % mod;
    }
    else
    {
      dp[i] = ((2 * dp[i - 1]) - dp[freq[s[i - 1] - 'A'] - 1] + mod) % mod;
    }
    freq[s[i - 1] - 'A'] = i;
    // printf("dp[%d] = %d\n", i, dp[i]);
  }

  return (dp[s.size()]) % mod;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--)
  {
    string str;
    cin >> str;
    // cout << str.length() << endl;
    cout << distSubseq_old(str) << endl;
  }
  return 0;
}
