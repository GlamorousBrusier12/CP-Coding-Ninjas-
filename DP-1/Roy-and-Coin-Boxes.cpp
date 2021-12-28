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
        int n, m;
        cin >> n >> m;
        int arr[n+1];
        memset(arr, 0, (n+1)*__SIZEOF_INT__);
        fin(i, 0, m){
            int l, r;
            cin >>l >> r;
            arr[l]+=1;
            if(r!=n)
            arr[r+1]-=1;
        }
        int minAns[m+1];
        memset(minAns, 0, __SIZEOF_INT__*(m+1));
        fin(i, 1, n+1){
            arr[i] += arr[i-1];
        }
        fde(i, n){
            minAns[arr[i]]++;
        }
        // fin(i, 0, m+1){
        //     cout << minAns[i] << ' ';
        // }
        // cout << endl;
        minAns[0] = 0;
        for(int i = m-1; i>=0; i--){
            minAns[i] += minAns[i+1];
        }
        // fin(i, 0, m+1){
        //     cout << minAns[i] << ' ';
        // }
        // cout << endl;
        int q;
        cin >> q;
        fin(i, 0, q){
            int num;
            cin >> num;
            cout << (num<=m?minAns[num]:0) << endl;
        }
    }
    return 0;
}