#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef pair<int, char> pic;
typedef vector<long long> vi;
typedef long long ll;
typedef pair<int, int> pii;
ll merge(vi &arr, int si , int ei){
    ll ans = 0;
    if(si < ei){    
        ll mid = si + (ei - si)/2, s1, s2;
        s1 = mid-si+1, s2 = ei - mid;
        ll arr1[s1],arr2[s2];
        for(int i = 0; i<s1; i++){
            arr1[i] = arr[si+i];
        }
        for(int i = 0; i<s2; i++){
            arr2[i] = arr[si+s1+i];
        }
        ll i = 0, j = 0, k = si, sumSofar = 0;
        while(i < s1 && j < s2){
            if(arr1[i] < arr2[j]){
                sumSofar += arr1[i];
                // printf("ssf = %d, %d %d\n", sumSofar,i, j);
                arr[k++] = arr1[i++]; 
            }else{
                ans += sumSofar;
                // printf("ans = %d, %d %d\n", ans, j, sumSofar);
                arr[k++] = arr2[j++];
            }
        }
        while(i < s1){
            arr[k++] = arr1[i++];
        }
        while(j < s2){
            // printf("ans = %d, %d %d\n", ans, j, sumSofar);
            ans += sumSofar;
            arr[k++] = arr2[j++];
        }
        // printf("%d is the answer of (%d,%d)   ", ans, si, ei);
    }
    return ans;
}
ll mergeSort(vi &arr, int si, int ei){
    ll ans = 0;
    if(si < ei){
        ll mid = si + (ei - si)/2;
        ll leftAns = mergeSort(arr, si, mid);
        ll rightAns = mergeSort(arr, mid+1, ei);
        ll mergeAns = merge(arr, si, ei);
        ans = leftAns + rightAns + mergeAns;
        // printf("(%d, %d)=>left ans : %d, right ans: %d, merge ans %d\n", si, ei, leftAns, rightAns, mergeAns);
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
        vi arr(n);
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        cout << mergeSort(arr, 0, n-1) << endl;
        // for(int i = 0; i<n; i++){
        //     cout << arr[i] << ' ';
        // }
        // cout << '\n';
    }
    return 0;
}