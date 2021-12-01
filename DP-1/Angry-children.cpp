#include<bits/stdc++.h>
#include<iostream>
#define fin(i, s, n) for(int i = s; i<n; i++)
#define fde(i, n) for(int i = n; i>=0; i--)
#define ll long long
#define mod 1000000007
using namespace std;
ll calcUnfairness(ll arr[], ll n){
    ll sum = 0, ans = 0;
    fin(i, 0, n){
        sum+= arr[i];
    }
    for(int i= n-1; i>0; i--){
        ans += (arr[i]*(i) - (sum - arr[i]));
        sum -= arr[i];
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll arr[n];
        fin(i, 0, n){
            cin >> arr[i];
        }
        sort(arr, arr+n);
        ll ans = LONG_MAX;
        ll dp[n];
        ll runningSum = 0;
        memset(dp, 0, n);
        fin(i, n-k, n){
            runningSum += arr[i];
        }
        ll currAns = calcUnfairness(arr+n-k, k);
        dp[n-k] = currAns;
        for(int i = n-k-1; i>=0; i--){
            ll prevAns = dp[i+1];
            // removing all the diff related to arr[i+k]
            currAns = prevAns - (arr[i+k]*(k-1)-(runningSum-arr[i+k]));
            // adding all the diff related to arr[i]
            currAns +=  ((runningSum-arr[i+k])- arr[i]*(k-1));
            dp[i] = currAns;
            runningSum = runningSum - arr[i+k]+ arr[i];
        }
        for(int i = 0; i<n-k+1; i++){
            ans =  min(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}