#include<iostream>
#include<bits/stdc++.h>
int MOD=pow(10, 9)+7;
using namespace std;
int numBalancedBst(int n){
    if(n == 0 || n == 1) return 1;
    if(n==2) return 3;
    int ans = 0;
    int x = numBalancedBst(n-1);
    int y = numBalancedBst(n-2);

    long one = (long)x*x;
    long two = (long)x*y*2;
    int a1 = (int)(one%MOD);
    int a2 = (int)(two%MOD);
    ans = (a1+a2)%MOD;
    return ans;
}
int main(){
    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << numBalancedBst(n) << endl;

    }
    return 0;
}
