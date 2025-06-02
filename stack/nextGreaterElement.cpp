#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find next greater element for each array element
    vector<int> nextGreaterElements(vector<int>& arr) {
        // Your implementation goes here
        vector<int> ans(arr.size(), 0);
        stack<int> st;

        for(int i = arr.size()-1; i >= 0; i--) {
            while(!st.empty() and st.top() <= arr[i]) {
                st.pop();
            }
            ans[i] = (st.empty()) ? -1 : st.top();

            st.push(arr[i]);
        }
        return ans;
    }
};

int main() {
    /*
    Next Greater Element Problem:
    For each element in array, find the first greater element that appears to its right.
    If no greater element exists, use -1.

    Example:
    Array:  [4, 5, 2, 25, 7, 8]
    Result: [5, 25, 25, -1, 8, -1]

    Explanation:
    4 -> 5 (next greater)
    5 -> 25 (next greater)
    2 -> 25 (next greater)
    25 -> -1 (no greater element)
    7 -> 8 (next greater)
    8 -> -1 (no greater element)
    */

    Solution sol;

    // Test Case 1: Basic case
    vector<int> arr1 = {4, 5, 2, 25, 7, 8};
    vector<int> result = sol.nextGreaterElements(arr1);
    
    cout << "Test Case 1:\n";
    cout << "Array:  ";
    for(int num : arr1) cout << num << " ";
    cout << "\nResult: ";
    for(int num : result) cout << num << " ";
    cout << "\n\n";

    // Test Case 2: Decreasing sequence
    vector<int> arr2 = {5, 4, 3, 2, 1};
    result = sol.nextGreaterElements(arr2);
    
    cout << "Test Case 2 (Decreasing sequence):\n";
    cout << "Array:  ";
    for(int num : arr2) cout << num << " ";
    cout << "\nResult: ";
    for(int num : result) cout << num << " ";
    cout << "\n\n";

    // Test Case 3: Increasing sequence
    vector<int> arr3 = {1, 2, 3, 4, 5};
    result = sol.nextGreaterElements(arr3);
    
    cout << "Test Case 3 (Increasing sequence):\n";
    cout << "Array:  ";
    for(int num : arr3) cout << num << " ";
    cout << "\nResult: ";
    for(int num : result) cout << num << " ";
    cout << "\n";

    return 0;
}