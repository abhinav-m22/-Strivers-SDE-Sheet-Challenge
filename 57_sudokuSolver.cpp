#include<bits/stdc++.h>
using namespace std;

bool isSafeInRow(int grid[9][9], int row, int num){
    for(int i = 0; i < 9; i++){
        if(grid[row][i] == num){
            return false;
        }
    }
    return true;
}

bool isSafeInColumn(int grid[9][9], int col, int num){
    for(int i = 0; i < 9; i++){
        if(grid[i][col] == num){
            return false;
        }
    }
    return true;
}

bool isSafeInGrid(int grid[9][9], int row, int col, int num){
    int rowFactor = row - (row%3);
    int colFactor = col - (col%3);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i+rowFactor][j+colFactor] == num){
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int grid[9][9], int row, int col, int num){
    if(isSafeInRow(grid, row, num) && isSafeInColumn(grid, col, num) && isSafeInGrid(grid, row, col, num)){
        return true;
    }
    return false;
}

bool findEmptyLocation(int grid[9][9], int& row, int& col){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(grid[i][j] == 0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

// Time Complexity: O(9(n ^ 2))
bool isItSudoku(int grid[9][9]) {
    int row, col;
    if(!findEmptyLocation(grid, row, col)){
        return true;
    }

    for(int i = 1; i <= 9; i++){
        if(isSafe(grid, row, col, i)){
            grid[row][col] = i;
            if(isItSudoku(grid)) return true;
            grid[row][col] = 0;
        }
    }
    return false;
}
