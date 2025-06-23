#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Function to find shortest transformation sequence length
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Your implementation goes here
    }
};

int main() {
    /*
    Example:
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot","dot","dog","lot","log","cog"]

    Transformation sequence:
    hit -> hot -> dot -> dog -> cog
    
    Expected output: 5 (length of sequence)

    Rules:
    1. Only one letter can be changed at a time
    2. Each transformed word must exist in wordList
    3. Return 0 if transformation is impossible
    */

    Solution sol;
    
    // Test Case 1: Valid transformation
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    
    int result = sol.ladderLength(beginWord, endWord, wordList);
    cout << "Test Case 1:\n";
    cout << "Begin Word: " << beginWord << "\n";
    cout << "End Word: " << endWord << "\n";
    cout << "Word List: ";
    for(const string& word : wordList) cout << word << " ";
    cout << "\nShortest sequence length: " << result << "\n";

    // Test Case 2: Impossible transformation
    beginWord = "hit";
    endWord = "cog";
    wordList = {"hot","dot","dog","lot","log"};  // 'cog' not in wordList
    
    cout << "\nTest Case 2:\n";
    result = sol.ladderLength(beginWord, endWord, wordList);
    cout << "Shortest sequence length: " << result << "\n";

    return 0;
}