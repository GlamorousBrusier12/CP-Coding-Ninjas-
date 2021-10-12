#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef vector<int> vi;
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int t;
    // cin >> t;
    // while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int i = 0, j = 1, ans = 0;
        for(; j< arr.size(); j++){
            if(i == j) continue;
            if(arr[j] - arr[i]>=k){
                ans += arr.size()-j;
                i++;
                j--;
            }
        }
        cout << ans << endl;
    // }
    return 0;
}