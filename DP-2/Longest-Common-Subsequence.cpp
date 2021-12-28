#include<bits/stdc++.h>
#include<iostream>
#define fin(i, s, n) for(int i = s; i<n; i++)
#define fde(i, n) for(int i = n; i>=0; i--)
#define ll long long
#define mod 1000000007
using namespace std;
int lcs(string s1, string s2){
  int n = s1.length(), m = s2.length();
  int dp[n+1][m+1];
  fin(i, 0, n+1){
    memset(dp[i], 0, sizeof(dp[i]));
  }
  fin(i, 0, n+1){
    dp[i][0] = 0;
  }
  fin(i, 0, m+1){
    dp[0][i] = 0;
  }
  fin(i, 1, n+1){
    fin(j, 1, m+1){
      if(s1[n-i] == s2[m-j]){
        dp[i][j] = dp[i-1][j-1]+1;
      }else{
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  // fin(i, 0, n+1){  
  //   fin(j, 0, m+1){
  //     cout << dp[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  return dp[n][m];
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        cout << lcs(s1, s2) << endl;
    }
    return 0;
}