#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef pair<int, char> pic;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;

int partition(int input[], int si, int ei){
    int count = 0;
    int pivot = input[si];
    for(int i=si; i<=ei;i++){
        if(input[i]< pivot){
            count++;
        }
    }
    int pivotIndex = si + count;
    input[si] = input[pivotIndex];
    input[pivotIndex] = pivot;
    int i = si, j = ei, temp;
    while(i < pivotIndex && j > pivotIndex){
        while(input[i]< pivot && i < pivotIndex){
			i++;
        }
        while(input[j]>= pivot && j > pivotIndex ){
			j--;
        }
        temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        i++, j--;
    }
    return pivotIndex;
}

void qs(int input[], int si, int ei){
	if(si>=ei){
        return;
    }    
    int pivotIndex = partition(input, si, ei);
    qs(input, si, pivotIndex-1);
    qs(input, pivotIndex+1, ei);
}
void quickSort(int input[], int size) {
	qs(input, 0, size-1);
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
        quickSort(arr, n);
        for(int i = 0; i<n; i++){
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}