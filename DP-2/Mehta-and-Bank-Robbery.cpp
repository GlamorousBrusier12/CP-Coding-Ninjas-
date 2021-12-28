#include<bits/stdc++.h>
#include<iostream>
#define fin(i, s, n) for(int i = s; i<n; i++)
#define fde(i, n) for(int i = n; i>=0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;
class Pair{
  public:
  int weight;
  int profit;
  Pair(){
    weight = 0;
    profit = 0;
  }
  Pair(int w, int p){
    weight = w;
    profit = p;
  }
};
// sorting the array based on the profits
bool compareProfit(Pair p1, Pair p2){
  return (p1.profit < p2.profit);
}
int prime[11] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int maxProfit_with_primes(Pair arr[], int n, int maxWeight){
  int ans = 0;
  sort(arr, arr+n, compareProfit);
  // fin(i, 0, n){
  //   cout << arr[i].profit << ' ';
  // }
  // cout << endl;
  // fin(i, 0, n){
  //   cout << arr[i].weight << ' ';
  // }
  // cout << endl;
  int dp[2][n+1][maxWeight+1];
  int flag = 1;
  
  // base case where no primes are included
  fin(i, 0, n+1){
    dp[0][i][0] = 0;
  }
  fin(i, 0, maxWeight+1){
    dp[0][0][i] = 0;
  }
  fin(i,1, n+1){
    fin(j, 1, maxWeight+1){
      dp[0][i][j] = dp[0][i-1][j];
      if(j >= arr[i-1].weight){
        dp[0][i][j] = max(dp[0][i-1][j], dp[0][i-1][j-arr[i-1].weight] + arr[i-1].profit);
      }
    }
  }
  
  fin(p, 1, 11){
    flag = p%2;
    fin(i, 0, n+1){
      dp[flag][i][0] = 0;
    }
    fin(i, 0, maxWeight+1){
      dp[flag][0][i] = 0;
    }
    fin(i, 1, n+1){
      fin(j, 1, maxWeight+1){
        dp[flag][i][j] = dp[flag][i-1][j];
        if(j >= arr[i-1].weight){
          
        dp[flag][i][j] = max(dp[flag][i][j], max(dp[flag][i-1][j-arr[i-1].weight]+arr[i-1].profit, dp[flag^1][i-1][j-arr[i-1].weight]+prime[p]*arr[i-1].profit));

        } 
      }
    }
    flag = flag ^ 1;
  }
  ans = dp[flag^1][n][maxWeight];
  return ans;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while(t--){
    int n, maxWeight;
    cin >> n >> maxWeight;
    Pair arr[n];
    fin(i, 0, n){
      cin >> arr[i].profit;
    }
    fin(i, 0, n){
      cin >> arr[i].weight;
    }
    cout << maxProfit_with_primes(arr, n, maxWeight) << endl ;
  }
  return 0;
}