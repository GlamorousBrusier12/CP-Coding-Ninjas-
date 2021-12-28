#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef pair<int, char> pic;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
void merge(int arr[], int si, int ei){
    int mid = si + (ei- si)/2;
    int length = mid-si+1, s1, s2;
    s1 = length, s2 = ei - mid;
    int  arr1[length], arr2[ei-mid];
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
}
void mergesort(int arr[], int si , int ei){
    if(si < ei){
        // cout << si << ei << endl;
        int mid = si + (ei- si)/2;
        mergesort(arr, si, mid);
        mergesort(arr, mid+1, ei);
        merge(arr, si, ei);
    }
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
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        mergesort(arr, 0, n-1);
        for(int i = 0; i<n; i++){
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}