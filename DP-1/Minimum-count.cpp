#include<bits/stdc++.h>
#include<iostream>
#define fin(i, s, n) for(int i = s; i<n; i++)
#define fde(i, n) for(int i = n; i>=0; i--)
#define ll long long
#define mod 1000000007
using namespace std;
int  minCount(int n){
    int ans[n+1];
    ans[0] = 0, ans[1] = 1, ans[2] = 2;
    fin(i, 3, n+1){
        int smallAns = i-1;
        // fin(j, 1, sqrt(i)+1){
        for(int j = sqrt(i); j >= 1 ; j--){
            smallAns = min(smallAns, ans[i-j*j]);
        }
        ans[i] = smallAns+1;
    }
    return ans[n];
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
        cout << minCount(n) << endl;
    }
    return 0;
}