#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find distance of nearest cell having 1
vector<vector<int>> nearestDistance(vector<vector<int>>& grid) {
    // Your implementation goes here
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n, vector<int> (m, 0));
    vector<vector<int>> distance(n, vector<int>(m, 0));

    queue<pair<pair<int, int>, int>> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1) {
                q.push({{i, j}, 0});
                visited[i][j] = 1;
            } else {
                visited[i][j] = 0;
            }
        }
    }

    vector<int> delrow = {-1, 0, +1, 0};
    vector<int> delcol = {0, +1, 0, -1};

    while(!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;

        distance[row][col] = dist;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];

            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && visited[newrow][newcol] == 0) {
                visited[newrow][newcol] = 1;
                q.push({{newrow, newcol}, dist + 1});
            }
        }
    }

    return distance;
}

// Helper function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    /*
    Example:
    Input Matrix:
    0 1 0
    0 0 0
    1 0 1

    Expected Output (Distance Matrix):
    1 0 1 
    1 1 1 
    0 1 0 

    Explanation:
    - For cells with 1, distance is 0
    - For 0s, find minimum Manhattan distance to any 1
    - Distance[i][j] = minimum steps needed to reach nearest 1
    */

    vector<vector<int>> grid = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 0, 1}
    };

    cout << "Input Matrix:" << endl;
    printMatrix(grid);

    vector<vector<int>> result = nearestDistance(grid);

    cout << "\nDistance Matrix:" << endl;
    printMatrix(result);

    // Test case 2: Matrix with isolated zeros
    vector<vector<int>> grid2 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "\nTest Case 2:" << endl;
    cout << "Input Matrix:" << endl;
    printMatrix(grid2);

    result = nearestDistance(grid2);
    cout << "\nDistance Matrix:" << endl;
    printMatrix(result);

    return 0;
}