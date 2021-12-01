#include<bits/stdc++.h>
#include<iostream>
#define fin(i, s, n) for(int i = s; i<n; i++)
#define fde(i, n) for(int i = n; i>=0; i--)
#define ll long long
using namespace std;
int largestBiotonicSequence(int arr[], int n){
    // step - 1
    // find the lis array
    int lis[n];
    lis[0] = 1;
    fin(i, 1, n){
        int ans = 1;
        fde(j, i-1){
            if(arr[j]<arr[i]){
                ans = max(ans, lis[j]+1);
            }
        }
        lis[i]= ans;
    }
    // step-2 
    // find the lds arr
    int lds[n];
    lds[n-1] = 1;
    fde(i, n-2){
        lds[i]=1;
        fin(j, i+1, n){
            if(arr[j]<arr[i]){
                lds[i] = max(lds[i], lds[j]+1);
            }
        }
    } 
    // step - 3 
    //  find the ans
    int ans = 1;
    fin(i, 0, n){
        ans = max(ans, lds[i]+lis[i]-1);
    }
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
        int arr[n];
        fin(i, 0, n){
            cin >> arr[i];
        }
        cout << largestBiotonicSequence(arr, n) << endl;
    }
    return 0;
}