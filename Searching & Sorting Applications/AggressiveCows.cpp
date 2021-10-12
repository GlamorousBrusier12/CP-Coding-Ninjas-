#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
bool check(ll* arr, int n, int d, int c){
    ll a = arr[0], k = 0, b;
    for(int i = 1; i<n; i++){
        b = arr[i];
        if(b - a >= d) {
            a = b;
            k++;
        }
    }
    return (k>=c-1);
}
int main()
{
    int t;
    // t = 1;
    freopen("input.txt", "r", stdin);
    freopen("ouput.txt", "w", stdout);
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        ll arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr+n);
        ll d = arr[n-1] - arr[0];
        ll s = 0, e = d;
        // for (int i = d; i >0; i--)
        // {
        //     cout <<"i: " << i << ',' << check(arr, n, i, c) << endl;
        // }
        ll mid, ans;
        // cout << "Binary Search: " << endl;
        while(s<=e){
            //cout << s << ", " << e << endl;
            mid = (s+e)/2;
            if(check(arr, n, mid, c)){
                ans = mid;
                s = mid+1;
            }else{
                e = mid -1;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}