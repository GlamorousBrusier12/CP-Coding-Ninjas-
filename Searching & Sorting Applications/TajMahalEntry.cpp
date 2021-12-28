#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef pair<int, char> pic;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    vi arr(t);
    for(int i = 0; i<t;i++){
        cin >> arr[i];
    }
    vi ans(t);
    for(int i = 0; i<t; i++){
        int v = (arr[i]-i)/t;
        if((arr[i]-i)%t != 0) v++;
        ans[i] = v;
    }
    int a = 0;
    for(int i = 1; i<ans.size(); i++){
        if(ans[i] < ans[a]){
            a = i;
        }
    }
    cout << a+1   << endl;
    return 0;
}