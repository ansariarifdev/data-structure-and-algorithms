#include <bits/stdc++.h>
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
    // Your implementation goes here
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