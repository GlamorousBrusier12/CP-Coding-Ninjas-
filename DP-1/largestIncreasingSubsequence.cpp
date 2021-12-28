#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fin(i, s, n) for(int i = s; i<n; i++)
#define fde(i, n) for(int i = n; i>=0; i--)
#define ll long long
int lis(int arr[], int n){
    int output[n];
    output[0] = 1;
    fin(i, 1, n){
        int ans = 1;
        fde(j, i-1){
            if(arr[j]<arr[i]){
                ans = max(ans, output[j]+1);
            }
        }
        output[i]= ans;
    }
    int best = 0;
    fin(i, 0, n){
        best = max(best, output[i]);
    }
    fin(i, 0, n){
        cout << output[i]<< ' ' ;
    }
    cout << endl;
    return best;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int arr[n];
    fin(i, 0, n){
        cin >> arr[i];
    }
    cout << lis(arr, n) << endl;
    return 0;
}