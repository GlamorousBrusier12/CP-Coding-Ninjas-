#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    int m = INT_MIN;
    int *h = new int[100001];
    memset(h, 0, sizeof(int)*100001);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        // cout << x << ' ' << y << endl;
        h[x/2] = max(h[x/2], y);
        m = max(m, x);
    }
    int area = 0, currMax= 0;
    for(int i = m/2; i>0; i--){
        currMax = max(currMax, h[i]);
        // if(h[i]>h[i+1]){
        //     area+=h[i];
        // }else{
        // }
        // cout << "(" << i << "," << h[i]<< ")" << ' ';
        area+=currMax;
    }
    cout << 2*area << endl;
    return 0;
}