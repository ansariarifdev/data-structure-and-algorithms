#include <iostream>
#include <vector>
using namespace std;

// Function to count number of enclaves
int numEnclaves(vector<vector<int>>& grid) {
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