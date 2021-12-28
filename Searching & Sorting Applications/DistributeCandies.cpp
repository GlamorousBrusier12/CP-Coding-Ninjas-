#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef pair<int, char> pic;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
bool check(int *arr, int n, int numChocolates, int numfriends){
    int ans = 0;
    for(int i = 0; i<n; i++){
        ans += arr[i]/numChocolates;
    }
    return (ans>=numfriends);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int maxi = INT_MIN;
        int arr[n];
        for(int i = 0; i<n; i++){
            cin >> arr[i];
            maxi = max(arr[i], maxi);
        }
        int si = 1, ei = maxi, ans;
        while(si <= ei){
            int mid = si + (ei-si)/2;
            if(check(arr, n, mid, k)){
                ans = mid;
                si = mid + 1;
            }else{
                ei = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}