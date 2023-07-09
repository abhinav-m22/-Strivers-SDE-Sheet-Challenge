#include<bits/stdc++.h>
using namespace std;

void add(vector<vector<int>> &board, vector<vector<int>> &ans, int n){
    vector<int> v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            v.push_back(board[i][j]);
        }
    }
    ans.push_back(v);
}

bool isSafe(int row, int col, vector<vector<int>>& board, int n){
    int dupRow = row, dupCol = col;
    while(row >= 0 && col >= 0){
        if(board[row][col] == 1) return false;
        row--, col--;
    }
    row = dupRow, col = dupCol;
    while(col >= 0){
        if(board[row][col] == 1) return false;
        col--;
    }
    row = dupRow, col = dupCol;
    while(row < n && col >= 0){
        if(board[row][col] == 1) return false;
        row++, col--;
    }
    return true;
}

void solve(vector<vector<int>>& board, vector<vector<int>>& ans, int col, int n){
    if(col == n){
        add(board, ans, n);
        return;
    }

    for(int row = 0; row < n; row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 1;
            solve(board, ans, col+1, n);
            board[row][col] = 0;
        }
    }
}

// Time Complexity: (N! * N) nearly.
vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solve(board, ans, 0, n);
    return ans;
}