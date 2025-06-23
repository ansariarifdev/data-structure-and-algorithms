#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find order of characters in alien language
    string findOrder(vector<string>& dict, int N, int K) {
        // Your implementation goes here
    }
private:
    // Helper function to build graph from dictionary words
    void buildGraph(vector<string>& dict, vector<vector<int>>& adj) {
        // Your implementation goes here
    }
};

int main() {
    /*
    Example:
    dict = ["baa", "abcd", "abca", "cab", "cad"]
    N = 5 (number of words)
    K = 4 (size of alphabet, characters from 'a' to 'd')

    From the dictionary, we can determine:
    - 'b' comes before 'a' (from "baa" and "abcd")
    - 'c' comes before 'a' (from "cab" and "abcd")
    - 'd' comes after 'c' (from "cab" and "cad")

    Expected output: "bcad" or any valid alien alphabet order
    */

    Solution sol;
    
    // Test Case 1
    vector<string> dict1 = {"baa", "abcd", "abca", "cab", "cad"};
    int N1 = 5;
    int K1 = 4;
    
    string result = sol.findOrder(dict1, N1, K1);
    cout << "Test Case 1:" << endl;
    cout << "Dictionary: ";
    for(const string& s : dict1) cout << s << " ";
    cout << "\nAlphabet order: " << result << endl;

    // Test Case 2: Simple dictionary
    vector<string> dict2 = {"caa", "aaa", "aab"};
    int N2 = 3;
    int K2 = 3;
    
    cout << "\nTest Case 2:" << endl;
    cout << "Dictionary: ";
    for(const string& s : dict2) cout << s << " ";
    cout << "\nAlphabet order: " << sol.findOrder(dict2, N2, K2) << endl;

    return 0;
}