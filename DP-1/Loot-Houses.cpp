#include<bits/stdc++.h>
#include<iostream>
#define fin(i, s, n) for(int i = s; i<n; i++)
#define fde(i, s, e) for(int i = s; i>=e; i--)
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int arr[n];
    fin(i, 0, n) cin >> arr[i];
    int ans[n];
    ans[n-1] = arr[n-1];
    ans[n-2] = max(arr[n-1], arr[n-2]);
    fde(i, n-3, 0){
        ans[i] = max(ans[i+1], arr[i]+ans[i+2]);
    }
    cout << ans[0] << endl;
    return 0;
}