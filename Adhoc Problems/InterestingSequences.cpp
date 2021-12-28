#include<bits/stdc++.h>
#include<iostream>
using namespace std;
long long fun(int arr[], int n, int mid, int k, int l){
    long long decrease = 0, increase = 0;
    for(int i = 0; i<n; i++){
        if(arr[i]>mid)
            decrease+=(abs(arr[i]-mid));
        else 
            increase +=(abs(arr[i]-mid));
    }
    if(decrease > increase) return LLONG_MAX;
    long long ans = decrease*k+(increase-decrease)*l;
    return ans;
}
int main()
{
    int n, k, l;
    cin >> n >> k >> l;
    if(n==1) cout << 0 << endl;
    else{
        int arr[n], mini = LLONG_MAX, maxi = LLONG_MIN;
        for(int i = 0; i<n; i++){
            cin >> arr[i];
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        } 
        long long ans=LLONG_MAX;
        for(int i = mini; i<=maxi; i++){
            ans = min(ans, fun(arr, n, i, k, l));
        }
        cout << ans << endl;
    }
    return 0;
}