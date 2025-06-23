#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // Function to find previous smaller element for each array element
    vector<int> previousSmallerElements(vector<int>& arr) {
        // Your implementation goes here
        vector<int> ans(arr.size(), 0);
        stack<int> st;

        for(int i = 0; i <= arr.size()-1; i++) {
            while(!st.empty() and st.top() >= arr[i]) {
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
    Previous Smaller Element Problem:
    For each element in array, find the first smaller element that appears to its left.
    If no smaller element exists, use -1.

    Example:
    Array:  [4, 10, 5, 8, 3, 7]
    Result: [-1, 4, 4, 5, -1, 3]

    Explanation:
    4 -> -1 (no smaller element)
    10 -> 4 (first smaller on left)
    5 -> 4 (first smaller on left)
    8 -> 5 (first smaller on left)
    3 -> -1 (no smaller element)
    7 -> 3 (first smaller on left)
    */

    Solution sol;

    // Test Case 1: Basic case
    vector<int> arr1 = {4, 10, 5, 8, 3, 7};
    vector<int> result = sol.previousSmallerElements(arr1);
    
    cout << "Test Case 1:\n";
    cout << "Array:  ";
    for(int num : arr1) cout << num << " ";
    cout << "\nResult: ";
    for(int num : result) cout << num << " ";
    cout << "\n\n";

    // Test Case 2: Increasing sequence
    vector<int> arr2 = {1, 2, 3, 4, 5};
    result = sol.previousSmallerElements(arr2);
    
    cout << "Test Case 2 (Increasing sequence):\n";
    cout << "Array:  ";
    for(int num : arr2) cout << num << " ";
    cout << "\nResult: ";
    for(int num : result) cout << num << " ";
    cout << "\n\n";

    // Test Case 3: Decreasing sequence
    vector<int> arr3 = {5, 4, 3, 2, 1};
    result = sol.previousSmallerElements(arr3);
    
    cout << "Test Case 3 (Decreasing sequence):\n";
    cout << "Array:  ";
    for(int num : arr3) cout << num << " ";
    cout << "\nResult: ";
    for(int num : result) cout << num << " ";
    cout << "\n";

    return 0;
}