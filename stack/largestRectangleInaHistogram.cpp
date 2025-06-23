#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to find the largest rectangle area in histogram
    int largestRectangleArea(vector<int>& heights) {
        // Your implementation goes here
    }

private:
    // Helper function to find previous smaller element indices
    vector<int> previousSmaller(vector<int>& heights) {
        // Your implementation goes here
    }
    
    // Helper function to find next smaller element indices
    vector<int> nextSmaller(vector<int>& heights) {
        // Your implementation goes here
    }
};

int main() {
    /*
    Largest Rectangle in Histogram:
    Given an array of integers heights representing the histogram's bar height
    where the width of each bar is 1, return the area of the largest rectangle.

    Example:
    Heights: [2,1,5,6,2,3]
    
    Visual representation:
         6
       5 _
       _ |
    2  | |  3
    _  | | 2_
    | 1| | |_|
    |_||_|_|_|
    
    Largest Rectangle Area = 10 (5 height × 2 width)
    */

    Solution sol;

    // Test Case 1: Basic case
    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    cout << "Test Case 1:\n";
    cout << "Heights: ";
    for(int h : heights1) cout << h << " ";
    cout << "\nLargest Rectangle Area: " << sol.largestRectangleArea(heights1) << "\n\n";

    // Test Case 2: All same height
    vector<int> heights2 = {4, 4, 4, 4};
    cout << "Test Case 2 (All same height):\n";
    cout << "Heights: ";
    for(int h : heights2) cout << h << " ";
    cout << "\nLargest Rectangle Area: " << sol.largestRectangleArea(heights2) << "\n\n";

    // Test Case 3: Increasing heights
    vector<int> heights3 = {1, 2, 3, 4, 5};
    cout << "Test Case 3 (Increasing heights):\n";
    cout << "Heights: ";
    for(int h : heights3) cout << h << " ";
    cout << "\nLargest Rectangle Area: " << sol.largestRectangleArea(heights3) << "\n";

    return 0;
}