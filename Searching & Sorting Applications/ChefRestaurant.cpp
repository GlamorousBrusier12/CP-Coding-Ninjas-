#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        vector<pii> arr;
        int n, m;
        cin >> n >> m;
        for(int i = 0; i<n; i++){
            int a, b;
            cin >> a >> b;
            arr.push_back({a, b});
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < m; i++)
        {
            int time;
            cin >> time;
            int pos = lower_bound(arr.begin(), arr.end(),make_pair(time, 0)) - arr.begin();
            if(pos == 0){
                if(arr[pos].first == time){
                    cout << 0 << endl;
                }else{
                    cout << arr[pos].first - time << endl;
                }
            }else{
                int ans = -1;
                if(arr[pos-1].second > time){
                    ans = 0;
                }else if(pos < arr.size()){
                    ans = arr[pos].first - time;
                }
                cout << ans << endl;
            }
        }
        
    }
    return 0;
}