#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool inLimit(int n, int i, int j){
    return (i>=0 && j >= 0 && i<n && j<n);
}
void fillMaze(int **maze,int n, int ci, int cj, int **ans){
    if(ci == n-1 && cj == n-1){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cout << ans[i][j] << ' ' ;
            }
        }
        cout << endl;
        return;
    }
    if(!inLimit(n, ci , cj) || maze[ci][cj] == 0){
        return;
    }
    int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(int i = 0; i<4; i++){
        int newI = ci + arr[i][0];
        int newJ = cj + arr[i][1];
        if(!inLimit(n, newI , newJ) || maze[newI][newJ] == 0 || ans[newI][newJ] == 1){
            continue;
        }
        ans[newI][newJ] = 1;
        fillMaze(maze, n, newI, newJ, ans);
        ans[newI][newJ] = 0;
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int **maze = new int*[n];
    for(int i = 0; i<n; i++){
        maze[i] = new int[n];
    }
    for(int i = 0; i<n; i++){
        maze[i] = new int[n];
        for(int j = 0; j<n; j++){
            cin >> maze[i][j];
        }
    }
    int **solution = new int*[n];
    for(int i = 0; i<n; i++){
        solution[i] = new int[n];
        for(int j = 0; j<n; j++){
            solution[i][j] = 0;
        }
    }
    if(maze[0][0]==1){
    solution[0][0] = 1;
    }
    fillMaze(maze, n, 0, 0, solution);
    return 0;
}