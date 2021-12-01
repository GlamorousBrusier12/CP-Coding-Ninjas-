#include<bits/stdc++.h>
#include<iostream>
#define fin(i, s, n) for(int i = s; i<n; i++)
#define fde(i, n) for(int i = n; i>=0; i--)
#define ll long long
#define mod 1000000007
using namespace std;
int stairCase(int n){
    int ans[n+1];
    if(n == 0 || n == 1) return 1;
    ans[0] = 1, ans[1] = 1, ans[2] = 2;
    fin(i, 3, n+1){
        ans[i] = ((ans[i-1] + ans[i-2])%mod + ans[i-3])%mod;
    }
    return ans[n];
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << stairCase(n) << endl;
    }
    return 0;
}