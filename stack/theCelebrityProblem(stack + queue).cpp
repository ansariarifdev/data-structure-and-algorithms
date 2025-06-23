#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Function to find the celebrity
    int findCelebrity(vector<vector<int>>& M, int n) {
        // Your implementation goes here
    }
private:
    // Helper function to check if a is known by b
    bool knows(vector<vector<int>>& M, int a, int b) {
        return M[a][b] == 1;
    }
};

int main() {
    /*
    Celebrity Problem:
    In a party of n people, find the celebrity.
    A celebrity:
    1. Doesn't know anyone
    2. Is known by everyone else
    3. Matrix M[i][j] = 1 means i knows j
    4. Matrix M[i][j] = 0 means i doesn't know j
    
    Example:
    Matrix M = [
        [0 1 0]
        [0 0 0]  Person 1 is celebrity
        [0 1 0]
    ]
    */

    Solution sol;

    // Test Case 1: Basic case with celebrity
    vector<vector<int>> M1 = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    int n1 = 3;
    
    cout << "Test Case 1:\n";
    cout << "Matrix:\n";
    for(const auto& row : M1) {
        for(int x : row) cout << x << " ";
        cout << "\n";
    }
    int celeb = sol.findCelebrity(M1, n1);
    cout << "Celebrity: " << (celeb != -1 ? to_string(celeb) : "No celebrity") << "\n\n";

    // Test Case 2: No celebrity
    vector<vector<int>> M2 = {
        {0, 1},
        {1, 0}
    };
    int n2 = 2;
    
    cout << "Test Case 2 (No celebrity):\n";
    cout << "Matrix:\n";
    for(const auto& row : M2) {
        for(int x : row) cout << x << " ";
        cout << "\n";
    }
    celeb = sol.findCelebrity(M2, n2);
    cout << "Celebrity: " << (celeb != -1 ? to_string(celeb) : "No celebrity") << "\n\n";

    // Test Case 3: Everyone knows everyone
    vector<vector<int>> M3 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    int n3 = 3;
    
    cout << "Test Case 3 (Everyone knows everyone):\n";
    cout << "Matrix:\n";
    for(const auto& row : M3) {
        for(int x : row) cout << x << " ";
        cout << "\n";
    }
    celeb = sol.findCelebrity(M3, n3);
    cout << "Celebrity: " << (celeb != -1 ? to_string(celeb) : "No celebrity") << "\n";

    return 0;
}