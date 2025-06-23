#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    // Function to check if string has valid parentheses
    bool isValid(string s) {
        // Your implementation goes here
        stack<char> st;

        for(auto element: s) {
            if(element == '(' || element == '[' || element == '{') {
                st.push(element);
            } else {
                if(st.empty()) {
                    return false;
                }
                if((element == ')' and st.top() == '(') || (element == '}' and st.top() == '{') || (element == ']' and st.top() == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    /*
    Valid Parentheses Problem:
    Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
    determine if the input string is valid.

    Rules:
    1. Open brackets must be closed by the same type of brackets
    2. Open brackets must be closed in the correct order
    3. Every close bracket has a corresponding open bracket of the same type

    Examples:
    "()" -> true
    "()[]{}" -> true
    "(]" -> false
    "([)]" -> false
    "{[]}" -> true
    */

    Solution sol;
    
    // Test Case 1: Basic valid cases
    vector<string> validCases = {
        "()",
        "()[]{}",
        "{[]}"
    };

    cout << "Testing valid cases:\n";
    for(const string& s : validCases) {
        cout << "Input: " << s << " -> ";
        cout << (sol.isValid(s) ? "Valid" : "Invalid") << endl;
    }

    // Test Case 2: Invalid cases
    vector<string> invalidCases = {
        "(]",
        "([)]",
        "(((",
        "}{"
    };

    cout << "\nTesting invalid cases:\n";
    for(const string& s : invalidCases) {
        cout << "Input: " << s << " -> ";
        cout << (sol.isValid(s) ? "Valid" : "Invalid") << endl;
    }

    return 0;
}