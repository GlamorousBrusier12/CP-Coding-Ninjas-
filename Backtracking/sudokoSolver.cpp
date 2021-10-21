#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool findEmptyPos(int grid[9][9], int &row, int &col){
    for (int i = 0; i < 9; i++)
    {
        for (int  j = 0; j < 9; j++)
        {
            if(grid[i][j]==0){
                row = i, col = j;
                return true;
            }
        }
    }
    return false;
}
bool isSafe(int grid[9][9], int r, int c, int num){
    // checking for the row
    for(int i = 0; i<9; i++){
        if(grid[i][c] == num)
            return false;
    }
    // checking for the column
    for(int i = 0; i<9; i++){
        if(grid[r][i] == num)
            return false;
    }
    int rf = r - r%3, cf = c - c%3;
    // checking for the grid
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i+rf][j+cf] == num){
                return false;
            }
        }
    }
    return true;
}
bool solveSudoko(int grid[9][9]){
    int row, col;
    if(!findEmptyPos(grid, row, col)){
        return true;
    }
    for (int i = 1; i <= 9; i++)
    {
        if(isSafe(grid, row, col, i)){
            grid[row][col] = i;
            bool done = solveSudoko(grid);
            if(done) return done;
            else grid[row][col] = 0;
        }
    }
    return false;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n = 9;
    int grid[9][9];
    for(int i = 0; i<n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    cout << (solveSudoko(grid)==true?"true":"false")<< endl;
    // for(int i = 0; i<n; i++){
    //     for (int j = 0; j < n; j++){
    //         cout <<  grid[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    return 0;
}
