#include<bits/stdc++.h>
#include<iostream>
#define fin(i, s, n) for(int i = s; i<n; i++)
#define fde(i, n) for(int i = n; i>=0; i--)
#define ll long long
#define mod 1000000007
using namespace std;
bool inlimit(int ci, int cj, int n, int m){
    return (ci >=0 && ci < n && cj >=0 && cj < m);
}
int minHealthRequired_helper(int **arr, int n, int m, int ci, int cj, int **output){
    if(!inlimit(ci, cj, n, m)){
        return INT_MAX;
    }
    if(ci == n-1 && cj == m-1) return 0;
    if(ci == n-1 &&  cj == m-2 || ci == n-2 &&  cj == m-1){
        return 1;
    }
    if(output[ci][cj] != -1){
        return output[ci][cj];
    }
    int ans;
    int rightAns = minHealthRequired_helper(arr, n, m, ci+1, cj, output);
    if(rightAns!=INT_MAX){
        rightAns -= arr[ci+1][cj];
    }
    int leftAns = minHealthRequired_helper(arr, n, m, ci, cj+1, output);
    if(leftAns != INT_MAX) {
        leftAns -= arr[ci][cj+1];
    }
    ans = min(rightAns, leftAns);
    ans = (ans<=0?1:ans);
    output[ci][cj] = ans;
    return ans;
}
int minHealthRequired(int **arr, int n, int m){
    int ans;
    int **output = new int*[n];
    fin(i, 0, n){
        output[i] = new int[m];
        memset(output[i], -1, sizeof(int)*m);
    }
    ans = minHealthRequired_helper(arr, n, m ,0, 0, output);
    fin(i, 0, n){
        delete [] output[i];
    }
    delete []output;
    return ans;
}

int minHealthrequired_i(int **arr, int n, int m){
    int ans[n][m];
    ans[n-1][m-1] = 0, ans[n-1][m-2] = 1, ans[n-2][m-1] = 1;
    fde(i, n-3){
        ans[i][m-1] = ans[i+1][m-1]-arr[i+1][m-1];
        if(ans[i][m-1]<=0){
            ans[i][m-1] = 1;
        }
    }
    fde(i, m-3){
        ans[n-1][i] = ans[n-1][i+1]-arr[n-1][i+1];
        if(ans[n-1][i]<=0){
            ans[n-1][i] = 1;
        }
    }
    fde(i,n-2){
        fde(j, m-2){
            int minimumAns = min(ans[i+1][j]-arr[i+1][j], ans[i][j+1]-arr[i][j+1]);
            if(minimumAns<=0){
                minimumAns = 1;
            }
            ans[i][j] = minimumAns;
        }
    }
    return ans[0][0];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int r, c;
        cin >> r >> c;
        int **grid = new int*[r];
        fin(i, 0, r){
            grid[i] = new int[c];
            fin(j, 0, c){
                cin >> grid[i][j];
            }
        }    
        cout  << minHealthrequired_i(grid, r, c) << endl;
        fin(i, 0, r){
            delete [] grid[i];
        }
        delete [] grid;
    }
    return 0;
}