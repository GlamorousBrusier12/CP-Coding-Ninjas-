#include<bits/stdc++.h>
#include<iostream>
#define fin(i, s, n) for(int i = s; i<n; i++)
#define fde(i, n) for(int i = n; i>=0; i--)
#define ll long long
#define mod 1000000007
#define gcd __gcd
using namespace std;
int  specialLisGcd(int arr[], int n){
    int dp[n][101];
    memset(dp, 0, __SIZEOF_INT__*n*101);
    dp[0][arr[0]] = 1;
    fin(i, 1, n){
        dp[i][arr[i]] = 1;
       fde(j, i-1){
           if(arr[j] < arr[i]){
            //    printf("(%d, %d)\n", arr[j], arr[i]);
               fin(k, 1, 101){
                   if(dp[j][k]>0){
                    int newGcd = gcd(k, arr[i]);
                    // cout << arr[i] << '=' << newGcd << endl;
                    dp[i][newGcd] = (dp[i][newGcd]+dp[j][k])%mod;
                   }
               }
           }
       }
    }
    int sum = 0;
    fin(i, 0, n){
        sum = (sum+dp[i][1])%mod;
    }
    // cout << endl;
    return sum;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        fin(i, 0, n){
            cin >> arr[i];
        }
        cout << specialLisGcd(arr,  n) << endl;
    }
    return 0;
}