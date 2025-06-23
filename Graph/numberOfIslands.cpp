#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS and mark visited cells
void dfs(vector<vector<char>>& grid, int i, int j, int rows, int cols) {
    // Your implementation goes here
}

// Function to count number of islands
int numIslands(vector<vector<char>>& grid) {
    // Your implementation goes here
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