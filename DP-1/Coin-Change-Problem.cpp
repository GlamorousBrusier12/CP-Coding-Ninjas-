#include<bits/stdc++.h>
#include<iostream>
#define fin(i, s, n) for(int i = s; i<n; i++)
#define fde(i, n) for(int i = n; i>=0; i--)
#define ll long long
#define mod 1000000007
using namespace std;
int coinChange_memo(int arr[], int n, int d, int **ans){
    if(d==0) return 1;
    if(d<0) return 0;
    if(n == 0) return 0;
    if(ans[d][n] != -1) return ans[d][n];
    int smallAns = coinChange_memo(arr, n, d-arr[0], ans);
    int smallAns2 = coinChange_memo(arr+1, n-1, d, ans);
    ans[d][n] = (smallAns2+smallAns)%mod;
    return ans[d][n];
}
int coinChange_i(int arr[], int n, int d){
    int **helper = new int*[d+1];
    fin(i, 0, d+1){
        helper[i] = new int[n+1];
        memset(helper[i], -1, sizeof(int)*(n+1));
    }
    fin(i, 0, d+1){
        helper[i][0] = 0;
    }
    fin(i, 1, n+1){
        helper[0][i] = 1;

    }
    fin(i, 1, d+1){
        fin(j, 1, n+1){
            helper[i][j] = helper[i][j-1];
            int newDen = i-arr[n-j]; 
            if(newDen>=0){
                helper[i][j] = (helper[i][j]+ helper[newDen][j])%mod;
            }
        }
    }
    int ans = helper[d][n];
    fin(i, 0, d+1){
        delete [] helper[i];
    }
    delete [] helper;
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
        int d;
        cin >> d;
        int **helper = new int*[d+1];
        fin(i, 0, d+1){
            helper[i] = new int[n+1];
            memset(helper[i], -1, sizeof(int)*(n+1));
        }
        cout << coinChange_i(arr, n, d) << endl;
    }
    return 0;
}