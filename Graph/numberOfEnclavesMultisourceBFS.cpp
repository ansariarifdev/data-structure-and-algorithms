#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Implementation of the bfs function 
void bfs(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
   visited[row][col] = true;
   int n = grid.size();
   int m = grid[0].size();

   queue<pair<int, int>> q;
   q.push({row, col});

   vector<int> delrow = {-1, 0, +1, 0};
   vector<int> delcol = {0, +1, 0, -1};

   while(!q.empty()) {
    auto [currentRow, currentCol] = q.front();
    q.pop();

    for(int i = 0; i < 4; i++) {
        int newrow = currentRow + delrow[i];
        int newcol = currentCol + delcol[i];

        if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] == 1 && visited[newrow][newcol] == false) {
            visited[newrow][newcol] = true;
            q.push({newrow, newcol});
        }
    }
   }
}
// Function to count number of enclaves
int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // row
    for(int j = 0; j < m; j++) {
        if(grid[0][j] == 1 and visited[0][j] == false) {
            bfs(0, j, grid, visited);
        }
        if(grid[n-1][j] == 1 and visited[n-1][j] == false) {
            bfs(n-1, j, grid, visited);
        }
    }

    // cols
    for(int i = 0; i < n; i++) {
        if(grid[i][0] == 1 and visited[i][0] == false) {
            bfs(i, 0, grid, visited);
        }
        if(grid[i][m-1] == 1 and visited[i][m-1] == false) {
            bfs(i, m-1, grid, visited);
        }
    }

    int count = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1 and visited[i][j] == false) {
                count++;
            }
        }
    }

    return count;

}

// Helper function to print the grid
void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    /*
    Example:
    Input Grid:
    0 0 0 0
    1 0 1 0
    0 1 1 0
    0 0 0 0

    Here:
    0 represents sea
    1 represents land
    An enclave is a group of 1s that cannot walk to the boundary
    
    Expected Output: 3
    Explanation:
    - The two 1s in the middle are enclaves
    - They cannot reach the boundary of the grid
    - Total count of land cells in enclaves = 3
    */

    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    cout << "Input Grid:" << endl;
    printGrid(grid);

    int result = numEnclaves(grid);
    cout << "\nNumber of enclaves: " << result << endl;

    // Test case 2: Grid with no enclaves
    vector<vector<int>> grid2 = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    cout << "\nTest Case 2:" << endl;
    cout << "Input Grid:" << endl;
    printGrid(grid2);

    result = numEnclaves(grid2);
    cout << "\nNumber of enclaves: " << result << endl;

    return 0;
}