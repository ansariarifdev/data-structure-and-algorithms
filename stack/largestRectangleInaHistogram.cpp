#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

class Solution {
public:
    // Function to find the largest rectangle area in histogram
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prev = previousSmaller(heights);
        vector<int> next = nextSmaller(heights);

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int height = heights[i];
            int left = prev[i];
            int right = next[i];
            if(right == -1) right = n; // If no smaller to the right, use n
            int width = right - left - 1;
            ans = max(ans, height * width);
        }
        return ans;
    }

private:
    // Helper function to find previous smaller element indices
    vector<int> previousSmaller(vector<int>& heights) {
        vector<int> previousSmaller(heights.size());
        stack<int> st;

        for(int i = 0; i < heights.size(); i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(st.empty()) {
                previousSmaller[i] = -1;
            } else {
                previousSmaller[i] = st.top();
            }

            st.push(i);
        }
        return previousSmaller;
    }
    
    // Helper function to find next smaller element indices
    vector<int> nextSmaller(vector<int>& heights) {
        vector<int> nextSmaller(heights.size());
        stack<int> st;

        for(int i = heights.size()-1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(st.empty()) {
                nextSmaller[i] = -1;
            } else {
                nextSmaller[i] = st.top();
            }

            st.push(i);
        }

        return nextSmaller;
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