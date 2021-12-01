#include<bits/stdc++.h>
#include<iostream>
#define fin(i, s, n) for(int i = s; i<n; i++)
#define fde(i, n) for(int i = n; i>=0; i--)
#define ll long long
#define mod 1000000007
using namespace std;
int minChocolates(int arr[], int n){
    if(n == 1 ){
        return 1;
    }
    if(n == 2){
        if(arr[0] == arr[1]){
            return 1;
        }else{
            return 3;
        }
    }
    int ans[n], sum = 0;
    ans[0] = 1;
    fin(i, 1, n){
        if(arr[i-1] < arr[i]){
            ans[i] = ans[i-1]+1;
        }else{
            ans[i] = 1;
        }
    }
    fde(i, n-2){
        if(arr[i]>arr[i+1] &&ans[i]<=ans[i+1]){
            ans[i] = ans[i+1]+1;
        }
    }
    fin(i, 0, n){
        sum+=ans[i];
    }
    return sum;
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
        int arr[n];
        fin(i, 0 , n){
            cin >> arr[i];
        }
        cout << minChocolates(arr, n) << endl;
    }
    return 0;
}