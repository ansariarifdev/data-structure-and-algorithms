#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS traversal
void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int city) {
    // Your implementation goes here
}

// Function to find number of provinces
int findProvinces(vector<vector<int>>& isConnected) {
    // Your implementation goes here
}

int main() {
    /*
    Example:
    isConnected = [
        [1,1,0],
        [1,1,0],
        [0,0,1]
    ]

    Visual representation:
    1 --- 2    3
    
    Expected Output: 2 provinces
    Explanation:
    - Cities 1 and 2 are connected, forming one province
    - City 3 is not connected to others, forming another province
    */

    vector<vector<int>> isConnected = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    int provinces = findProvinces(isConnected);
    cout << "Number of provinces: " << provinces << endl;

    // Additional test case
    vector<vector<int>> isConnected2 = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };

    provinces = findProvinces(isConnected2);
    cout << "Number of provinces in test case 2: " << provinces << endl;

    return 0;
}