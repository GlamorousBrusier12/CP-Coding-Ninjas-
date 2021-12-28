#include<bits/stdc++.h>
#include<iostream>
// #define long long ll; 
using namespace std;
long long  inversionCount(long long  arr[], int si, int ei){
    int ans = 0;
    if(si<ei){
        int mid = si+(ei-si)/2;
        long long  smallOutput1 = inversionCount(arr, si, mid);
        long long  smallOutput2 = inversionCount(arr, mid+1, ei);
        ans = smallOutput1 + smallOutput2;
        // mid operation
        int length = mid-si+1, s1, s2;
        s1 = length, s2 = ei - mid;
        long long  arr1[length], arr2[ei-mid];
        for(int q = 0; q < s1; q++){
            arr1[q] = arr[si+q];
        }
        for(int q = 0; q<s2; q++){
            arr2[q] = arr[si+length+q];
        }
        int i = 0, j = 0, k = si;
        while(i < s1 && j < s2){
            if(arr1[i] <= arr2[j]){
                arr[k] = arr1[i];
                k++, i++;
            }else{
                arr[k] = arr2[j];
                k++, j++;
                ans += (s1-i);
            }
        }
        while(i < s1){
            arr[k] = arr1[i];
            i++, k++;
        }
        while(j < s2){
            arr[k] = arr2[j];
            k++, j++;
        }
        // cout << "si: " << si<< " ,ei: "<<ei << " ans: " << ans<< "("<< smallOutput1<<"," << smallOutput2 << ")"<< endl;
    }
    return ans;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    long long  arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    cout << inversionCount(arr, 0, n-1) << endl;
    return 0;
}