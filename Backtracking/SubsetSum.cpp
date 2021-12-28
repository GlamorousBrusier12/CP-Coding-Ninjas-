#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int subsetSum(int *arr, int n, int k){
    if(k == 0) return 1;
    if(n ==  0 || k < 0)  return 0;
    int smallOutput1 = subsetSum(arr+1, n-1, k-arr[0]); 
    int smallOutput2 = subsetSum(arr+1, n-1, k);
    return smallOutput1+smallOutput2; 
} 
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << subsetSum(arr, n, k) << endl;
    }
    return 0;
}