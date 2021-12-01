#include<bits/stdc++.h>
#include<iostream>
#define fin(i, s, n) for(int i = s; i<n; i++)
#define fde(i, n) for(int i = n; i>=0; i--)
#define ll long long
#define mod 1000000007
using namespace std;
int substrings(string s) {
    int n = s.size();
    if(n == 1) return s[0]-'0';
    int ans[n];
    ans[0] = s[0]-'0';
    ans[1] = ans[0]+(s[1]-'0')*2+10;
    fin(i, 2, n){
        int addedAns = ans[i-1]-ans[i-2];
        int currentAns = (((1ll*addedAns)*10)%mod + (i+1) * (s[i]-'0'))%mod;
        ans[i] = (currentAns+ans[i-1])%mod;
    }
    return ans[n-1];
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << substrings(s) << endl;
    }
    return 0;
}