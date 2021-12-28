#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool inLimit(int n, int i, int j){
    return (i>=0 && j >= 0 && i<n && j<n);
}
void displayPossibleConfiguration(int **boxes,int n,int ci){
    if(ci == n){
        for(int i = 0; i<n; i++){
            for (int j = 0; j < n; j++)
            {
                cout << boxes[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
        return;
    }else{
        //check for the row part,
        // check for the column part
        // check for the diag (-1,-1)
        // chek for the diag (-1,1) 
        // chek for the up column (-1, 0) 
        // chek for the left row (0, -1)
        // if it passes  all the test cases then place it there 
        int arr[4][2] = { {0, -1}, {-1, 0}, {-1, 1}, {-1, -1}};
        for (int cj = 0; cj < n; cj++)
        {
            bool run = true;
            for(int i = 0; i<4 && run ; i++){
                int smallI = arr[i][0];
                int smallJ = arr[i][1];
                int newI = ci + smallI;
                int newJ = cj + smallJ;
                while (inLimit(n, newI, newJ)){
                    if(boxes[newI][newJ] == 1){
                        run = false;
                        break;
                    }  
                    newI += smallI;  
                    newJ += smallJ;  
                }
            }
            if(run){
                boxes[ci][cj] = 1; 
                displayPossibleConfiguration(boxes, n, ci+1);
                boxes[ci][cj] = 0;
            } 
            
        }
        //then proceed for the next row through the recursion 
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    t = 1;
    while(t--){
        int n;
        cin >> n;
        int **boxes = new int*[n];
        for(int i = 0; i<n; i++){
            boxes[i] = new int[n];
            for(int j = 0; j<n; j++){
                boxes[i][j] = 0;
            }
        }
        displayPossibleConfiguration(boxes, n, 0);
    }
    return 0;
}