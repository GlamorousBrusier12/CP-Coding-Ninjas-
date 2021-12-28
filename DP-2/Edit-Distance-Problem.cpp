#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define ll long long
#define mod 1000000007
using namespace std;
int editDistance_rec(string s1, string s2)
{
  int ans;
  if (s1.length() == 0 || s2.length() == 0)
  {
    return (s1.length() == 0) ? s2.length() : s1.length();
  }
  if (s1[0] == s2[0])
  {
    int smallAns = editDistance_rec(s1.substr(1), s2.substr(1));
    return smallAns;
  }
  // delete
  int smallAns1 = 1 + editDistance_rec(s1, s2.substr(1));
  // update
  int smallAns2 = 1 + editDistance_rec(s1.substr(1), s2.substr(1));
  // insert
  int smallAns3 = 1 + editDistance_rec(s1.substr(1), s2);
  ans = min(smallAns2, min(smallAns1, smallAns3));
  return ans;
}
int editDistance_helper(string s1, string s2, int **dp)
{
  int ans;
  if (s1.length() == 0 || s2.length() == 0)
  {
    return (s1.length() == 0) ? s2.length() : s1.length();
  }
  int n = s1.length(), m = s2.length();
  if (dp[n][m] != -1)
  {
    return dp[n][m];
  }
  if (s1[0] == s2[0])
  {
    int smallAns = editDistance_helper(s1.substr(1), s2.substr(1), dp);
    return smallAns;
  }
  // delete
  int smallAns1 = 1 + editDistance_helper(s1, s2.substr(1), dp);
  // update
  int smallAns2 = 1 + editDistance_helper(s1.substr(1), s2.substr(1), dp);
  // insert
  int smallAns3 = 1 + editDistance_helper(s1.substr(1), s2, dp);
  ans = min(smallAns2, min(smallAns1, smallAns3));

  // save the ans
  dp[n][m] = ans;

  return ans;
}
int editDistance_memo(string s1, string s2)
{
  int n = s1.length(), m = s2.length();
  int **dp = new int *[n + 1];
  fin(i, 0, n + 1)
  {
    dp[i] = new int[m + 1];
    memset(dp[i], -1, sizeof(int) * (m + 1));
  }
  int ans = editDistance_helper(s1, s2, dp);
  fin(i, 0, n + 1)
  {
    delete[] dp[i];
  }
  delete[] dp;
  return ans;
}
int editDistance_i(string s1, string s2)
{
  int n = s1.length(), m = s2.length();
  int dp[n + 1][m + 1];
  //fill first column
  fin(i, 0, n + 1)
  {
    dp[i][0] = i;
  }
  //fill first row
  fin(i, 0, m + 1)
  {
    dp[0][i] = i;
  }

  fin(i, 1, n+1){
    fin(j, 1, m+1){
      if(s1[n-i] == s2[m-j]){
        dp[i][j] = dp[i-1][j-1];
      }else{
        int smallAns1 = 1 + dp[i][j-1];
        int smallAns2 = 1 + dp[i-1][j-1];
        int smallAns3 = 1 + dp[i-1][j];
        dp[i][j] = min(smallAns1, min(smallAns2, smallAns3));
      }
    }
  }

  return dp[n][m];
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--)
  {
    string s1, s2;
    cin >> s1 >> s2;
    // cout << editDistance_rec(s1, s2) << ',';
    cout << editDistance_memo(s1, s2) << ',';
    cout << editDistance_i(s1, s2) << endl;
  }
  return 0;
}