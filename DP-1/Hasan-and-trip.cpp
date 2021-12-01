#include<bits/stdc++.h>
#include<iostream>
#define fin(i, s, n) for(int i = s; i<n; i++)
#define fde(i, n) for(int i = n; i>=0; i--)
#define ll long long
#define mod 1000000007
using namespace std;
double maxHappines(int x[], int y[], int k[], int n){
    double ans;
    fin(i, 0, n){
        cout << x[i] << ' ';
    }
    cout << endl;
    fin(i, 0, n){
        cout << y[i] << ' ';
    }
    cout << endl;
    fin(i, 0, n){
        cout << k[i] << ' ';
    }
    cout << endl;
    cout << endl;
    return ans;
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
        int x[n], y[n], k[n];
        fin(i, 0, n){
            cin >> x[i] >> y[i] >> k[i];
        }
        std::cout << std::setprecision(6) << std::fixed;
        cout << maxHappines( x,  y,  k,  n) << endl; 
        cout << endl;
    }
    return 0;
}