#include <bits/stdc++.h> 

void add_solution(vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    vector<int> temp;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row;
    int y = col;
    
    // checking for the same row
    while(y >= 0)
    {
        if(board[x][y] == 1 )
        {
            return false;
        }
        y--;
    }
    
    // not need to check the col as we are placing the queen as per it
    
    // checking the diagonal
    x = row;
    y = col;
    
    // upper side diagonal
    while(x >= 0 && y >=0)
    {
        if(board[x][y] == 1 )
        {
            return false;
        }
        y--;
        x--;
    }
    
    // down side diagonal
    x = row;
    y = col;
    
    while(x < n && y >=0)
    {
        if(board[x][y] == 1 )
        {
            return false;
        }
        y--;
        x++;
    }
    
    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    // base case
    if(col == n)
    {
        add_solution(ans, board, n);
        return;
    }
    
    // solve one case, rest is recursion
    for(int row = 0; row<n; row++)
    {
        if(isSafe(row, col, board, n))
        {
            // if placing queen is safe
            board[row][col] = 1;
            solve(col+1, ans, board, n);
            board[row][col] = 0; // backtrack
        }
    }
}


vector<vector<int>> nQueens(int n)
{
	// Write your code here
	vector<vector<int>> board(n, vector<int>(n, 0));
    
    vector<vector<int>> ans;
    
    solve(0, ans, board, n);
    
    return ans;
}