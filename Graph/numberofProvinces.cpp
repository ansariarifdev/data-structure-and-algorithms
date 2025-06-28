#include <iostream>
#include <vector>
using namespace std;

// Implementation of the solve function(using dfs)

void solve(vector<vector<int>>& isConnected, int index, vector<bool> &visited) {
    if(visited[index]) {
        return ;
    }

    visited[index] = true;
    for(int i = 0; i < isConnected.size(); i++) {
        if(isConnected[index][i] == 1 and visited[i] == false) {
            solve(isConnected, i, visited);
        }
    }
}
// Function to find number of provinces
int findProvinces(vector<vector<int>>& isConnected) {
    int provinces = 0;
    int n = isConnected.size();
    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            solve(isConnected, i, visited);
            provinces++;
        }
    }
    return provinces;
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