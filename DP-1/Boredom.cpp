#include<bits/stdc++.h>
#include<iostream>
#define fin(i, s, n) for(int i = s; i<n; i++)
#define fde(i, n) for(int i = n; i>=0; i--)
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        unordered_map<int, int> freq;
        fin(i, 0, n){
            int a;
            cin >> a;
            freq[a]++;
        } 
        int ans[1001];
        ans[0] = 0;
        ans[1] = freq[1];
        fin(i, 2, 1001){
            ans[i] = max(ans[i-1], ans[i-2]+freq[i]*i);
        }
        cout << ans[1000] << endl;
    }
    return 0;
}