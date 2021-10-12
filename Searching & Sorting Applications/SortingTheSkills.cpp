#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef pair<int, char> pic;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
bool check(vi arr){
    int n = arr.size();
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i] > arr[i+1]){
            if(arr[i]-arr[i+1]==1) {
                swap(arr[i], arr[i+1]);
            }else {
                // cout << i << ' ';
                return false;
            }
        }
    }
    return true;
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
        vi arr(n);
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }   
        cout << (check(arr)==true?"YES":"NO") << endl;
        
    }
    return 0;
}