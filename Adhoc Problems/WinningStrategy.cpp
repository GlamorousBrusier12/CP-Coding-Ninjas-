#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int  n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int count  = 0;
        bool isTerminating = false;
        for(int i = 0; i<n; i++){
            if(abs(arr[i]-(i+1)) > 2){
                isTerminating = true;
                break;
            }
        }
        if(isTerminating){
            cout << "NO" << endl;
        }
        else{
            for(int i = 0; i<n-1; i++){
                int index = i+1;
                if(abs(index-arr[i])>2 && abs(index+1-arr[i+1])>2) {
                    isTerminating = true;
                    break;
                }
                if(index == arr[i] || arr[i] < arr[i+1]) continue;
                else if(arr[i]> arr[i+1]) {
                    swap(arr[i], arr[i+1]);
                    count++;
                }
            }
            for(int i = 0; i<n-1; i++){
                int index = i+1;
                if(abs(index-arr[i])>2) {
                    isTerminating = true;
                    break;
                }
                if(index == arr[i] || arr[i] < arr[i+1]) continue;
                else if(arr[i]> arr[i+1]) {
                    swap(arr[i], arr[i+1]);
                    count++;
                }
            }
            cout << "YES" << endl;
            cout << count << endl;
        }
    }
    return 0;
}