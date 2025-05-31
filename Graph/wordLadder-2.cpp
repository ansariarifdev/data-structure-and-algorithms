#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find all shortest transformation sequences
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // Your implementation goes here
    }
private:
    // Helper function to find adjacent words
    vector<string> getNeighbors(string& word, unordered_set<string>& wordSet) {
        // Your implementation goes here
    }
};

// Helper function to print transformation sequences
void printSequences(const vector<vector<string>>& sequences) {
    if(sequences.empty()) {
        cout << "No valid transformation sequence exists.\n";
        return;
    }
    
    cout << "All shortest transformation sequences:\n";
    for(const auto& seq : sequences) {
        for(const string& word : seq) {
            cout << word << " -> ";
        }
        cout << "END\n";
    }
}

int main() {
    /*
    Example:
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot","dot","dog","lot","log","cog"]

    All possible shortest sequences:
    1. hit -> hot -> dot -> dog -> cog
    2. hit -> hot -> lot -> log -> cog

    Rules:
    1. Only one letter can be changed at a time
    2. Each transformed word must exist in wordList
    3. Return all possible shortest transformation sequences
    */

    Solution sol;
    
    // Test Case 1: Multiple valid sequences
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    
    cout << "Test Case 1:\n";
    cout << "Begin Word: " << beginWord << "\n";
    cout << "End Word: " << endWord << "\n";
    cout << "Word List: ";
    for(const string& word : wordList) cout << word << " ";
    cout << "\n\n";
    
    vector<vector<string>> sequences = sol.findLadders(beginWord, endWord, wordList);
    printSequences(sequences);

    // Test Case 2: No valid sequence
    wordList = {"hot","dot","dog","lot","log"};  // removing 'cog'
    cout << "\nTest Case 2 (Impossible transformation):\n";
    sequences = sol.findLadders(beginWord, endWord, wordList);
    printSequences(sequences);

    return 0;
}