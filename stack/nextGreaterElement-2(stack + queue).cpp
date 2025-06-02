#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find next greater elements in circular array
    vector<int> nextGreaterElements(vector<int>& nums) {
        // Your implementation goes here
    }
};

int main() {
    /*
    Next Greater Element II (Circular Array):
    Given a circular array, find the next greater element for each element.
    If no greater element exists, return -1.
    
    Example:
    Array: [1, 2, 1]
    Result: [2, -1, 2]
    
    Explanation (circular nature):
    1 -> 2 (next greater)
    2 -> -1 (no greater element)
    1 -> 2 (next greater, wrapping around to start)
    */

    Solution sol;

    // Test Case 1: Basic circular case
    vector<int> nums1 = {1, 2, 1};
    vector<int> result = sol.nextGreaterElements(nums1);
    
    cout << "Test Case 1 (Circular Array):\n";
    cout << "Array:  ";
    for(int num : nums1) cout << num << " ";
    cout << "\nResult: ";
    for(int num : result) cout << num << " ";
    cout << "\n\n";

    // Test Case 2: Decreasing sequence
    vector<int> nums2 = {5, 4, 3, 2, 1};
    result = sol.nextGreaterElements(nums2);
    
    cout << "Test Case 2 (Decreasing sequence):\n";
    cout << "Array:  ";
    for(int num : nums2) cout << num << " ";
    cout << "\nResult: ";
    for(int num : result) cout << num << " ";
    cout << "\n\n";

    // Test Case 3: All same elements
    vector<int> nums3 = {1, 1, 1, 1};
    result = sol.nextGreaterElements(nums3);
    
    cout << "Test Case 3 (All same elements):\n";
    cout << "Array:  ";
    for(int num : nums3) cout << num << " ";
    cout << "\nResult: ";
    for(int num : result) cout << num << " ";
    cout << "\n";

    return 0;
}