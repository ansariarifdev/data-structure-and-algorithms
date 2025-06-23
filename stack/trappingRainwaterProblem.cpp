#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the amount of water that can be trapped
    int trap(vector<int>& height) {
        // Your implementation goes here
    }
};

int main() {
    /*
    Trapping Rain Water Problem:
    Given n non-negative integers representing an elevation map 
    where width of each bar is 1, compute how much water it can trap.

    Example:
    Height: [0,1,0,2,1,0,1,3,2,1,2,1]
    
    Visual representation:
         3
         |
     2   |  2
     | 1 | 2| 1
    _|_|_|_|_|_
    0 2 1 1 2 1  <- Water trapped between bars
    
    Water trapped = 6 units
    */

    Solution sol;

    // Test Case 1: Basic case
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Test Case 1:\n";
    cout << "Heights: ";
    for(int h : height1) cout << h << " ";
    cout << "\nWater trapped: " << sol.trap(height1) << " units\n\n";

    // Test Case 2: No water can be trapped
    vector<int> height2 = {1, 2, 3, 4, 5};
    cout << "Test Case 2 (No water can be trapped):\n";
    cout << "Heights: ";
    for(int h : height2) cout << h << " ";
    cout << "\nWater trapped: " << sol.trap(height2) << " units\n\n";

    // Test Case 3: Valley shape
    vector<int> height3 = {4, 2, 0, 3, 2, 5};
    cout << "Test Case 3 (Valley shape):\n";
    cout << "Heights: ";
    for(int h : height3) cout << h << " ";
    cout << "\nWater trapped: " << sol.trap(height3) << " units\n";

    return 0;
}