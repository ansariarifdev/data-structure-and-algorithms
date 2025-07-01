#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/*
Problem: Rotten Oranges
Given a grid of oranges where:
0: Empty cell
1: Fresh orange
2: Rotten orange

Find minimum time taken for all oranges to rot.
Each rotten orange can rot adjacent fresh oranges in 1 unit time.
*/

// Function to find minimum time to rot all oranges
int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n, vector<int>(m));
    queue<pair<pair<int, int>, int>> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 2) {
                q.push({{i, j}, 0});
                visited[i][j] = 2;
            } else {
                visited[i][j] = 0;
            }
        }
    }

    int tmax = 0;
    vector<int> delrow = {-1, 0, +1, 0};
    vector<int> delcol = {0, +1, 0, -1};

    while(!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        tmax = max(tmax, t);
        q.pop();

        for(int i = 0; i < 4; i++) {
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];

            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] == 1 && visited[newrow][newcol] != 2) {
                visited[newrow][newcol] = 2;
                q.push({{newrow, newcol}, t + 1});
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1 and visited[i][j] != 2) {
                return -1;
            }
        }
    }
    return tmax;
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
    Initial grid:
    2 1 1
    1 1 0
    0 1 1

    Time 0:    Time 1:    Time 2:    Time 3:    Time 4:
    2 1 1     2 2 1     2 2 2     2 2 2     2 2 2
    1 1 0     2 1 0     2 2 0     2 2 0     2 2 0
    0 1 1     0 1 1     0 2 1     0 2 2     0 2 2

    Output: 4 (time units to rot all oranges)
    */

    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    cout << "Initial grid:" << endl;
    printGrid(grid);

    int result = orangesRotting(grid);
    
    if (result == -1) {
        cout << "\nImpossible to rot all oranges!" << endl;
    } else {
        cout << "\nTime required to rot all oranges: " << result << endl;
    }

    return 0;
}