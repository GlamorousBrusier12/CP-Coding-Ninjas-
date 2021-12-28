#include<bits/stdc++.h>
#include<iostream>
#define fin(i, s, n) for(int i = s; i<n; i++)
#define fde(i, n) for(int i = n; i>=0; i--)
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int **arr = new int*[n];
        fin(i, 0, n){
            arr[i] = new int[m];
            fin(j, 0, m){
                cin >> arr[i][j];
            }
        }
        int **dp = new int*[n];
        fin(i, 0, n){
            dp[i] = new int[m];
            memset(dp[i], 0, sizeof(int)*m);
        }
        // filling the last row with all 1's
        fin(i, 0, m){
            dp[n-1][i] = 1;
        }
        fin(i, 0, m){
            for(int j = n-2; j>=0; j--){
                if(arr[j+1][i] >= arr[j][i]){
                    dp[j][i] = dp[j+1][i] + 1;
                }else{
                    dp[j][i] = 1;
                }
            }
        }
        fin(i, 0, n){
            fin(j, 0, m){
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
        int k;
        cin >> k;
        fin(i, 0, k){
            int l, r;
            cin >> l >> r;
            bool ans = false;
            fin(j, 0, m){
                printf("(%d,%d)\n", dp[l-1][j]+l-1, r-l+1);
                if(dp[l-1][j]>=r-l+1){ ans = true; break;}
            }
            cout << (ans==true?"Yes":"No") << endl;
        }
        
    }
    return 0;
}