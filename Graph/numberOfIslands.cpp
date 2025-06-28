#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Implementation of the solve function 
void solve(vector<vector<char>> &grid, vector<vector<bool>> &visited, int rows, int cols) {
    int n = grid.size();
    int m = grid[0].size();
    visited[rows][cols] = true;

    queue<pair<int, int>> q;
    q.push({rows, cols});

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        // Visit the neighbours
        for(int delrows = -1; delrows <= 1; delrows++) {
            for(int delcols = -1; delcols <= 1; delcols++) {
                if(delrows == 0 and delcols == 0) {
                    continue;
                }
                if(abs(delrows) + abs(delcols) != 1) {
                    continue;
                }
                int nrow = row + delrows;
                int ncol = col + delcols;

                if((nrow >= 0 && nrow < n && ncol >= 0 && ncol < m ) && (visited[nrow][ncol] == false && grid[nrow][ncol] == '1')) {
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = true;
                }
            }
        }
    }
}
// Function to count number of islands
int numIslands(vector<vector<char>>& grid) {
    // Your implementation goes here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool> (m, false));
    int islands = 0;

    for(int rows = 0; rows < n; rows++) {
        for(int cols = 0; cols < m; cols++) {
            if(grid[rows][cols] == '1' and visited[rows][cols] == false) {
                solve(grid, visited, rows, cols);
                islands++;
            }
        }
    }
    return islands;
}

int main() {
    /*
    Example 1:
    Grid = [
        ['1','1','0','0','0'],
        ['1','1','0','0','0'],
        ['0','0','1','0','0'],
        ['0','0','0','1','1']
    ]

    Visual representation:
    11000  
    11000
    00100
    00011

    Expected Output: 3 islands

    Explanation:
    Island 1: Top-left four '1's
    Island 2: Middle single '1'
    Island 3: Bottom-right two '1's
    */

    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << "Number of islands: " << numIslands(grid) << endl;

    // Test case 2: Single island
    vector<vector<char>> grid2 = {
        {'1','1','1'},
        {'1','1','1'},
        {'1','1','1'}
    };

    cout << "Number of islands in test case 2: " << numIslands(grid2) << endl;

    return 0;
}