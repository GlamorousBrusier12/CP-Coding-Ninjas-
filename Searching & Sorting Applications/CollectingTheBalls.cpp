#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef pair<int, char> pic;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
bool check(int n, int k){
    int sum = 0;
    int curr = n;
    while(curr > 0){
		sum = sum + min(k, curr);
        curr = curr - k;
        curr = curr - curr/10;
    }
    return (sum *2 >= n);
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
        int ans;
        int si = 1, ei = n, mid;
        while(si <= ei){
            mid = si + (ei-si)/2;
            // cout << mid << " : ";
            if(check(n, mid)){
                // cout << 1 << endl;
                ans = mid;
                ei = mid -1;
            }else{
                // cout << 0 << endl;
                si = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}