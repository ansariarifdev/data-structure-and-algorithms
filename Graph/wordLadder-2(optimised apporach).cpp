#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find all shortest transformation sequences using bidirectional BFS
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // Your implementation goes here
    }

private:
    // Helper function for bidirectional BFS
    bool bfs(unordered_map<string, unordered_set<string>>& graph,
             unordered_set<string>& forward,
             unordered_set<string>& backward,
             unordered_set<string>& wordSet,
             bool isForward) {
        // Your implementation goes here
    }

    // Helper function to build paths using DFS
    void dfs(string& word, string& endWord,
             unordered_map<string, unordered_set<string>>& graph,
             vector<string>& path,
             vector<vector<string>>& paths) {
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
    Example with Bidirectional BFS optimization:
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot","dot","dog","lot","log","cog"]

    Forward BFS from "hit"  ←→  Backward BFS from "cog"
    Meet in the middle to find shortest paths more efficiently
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

    // Test Case 2: Larger word list to demonstrate optimization
    wordList = {"hot","dot","dog","lot","log","cog","fog","fig","dig","dim"};
    cout << "\nTest Case 2 (Larger word list):\n";
    sequences = sol.findLadders(beginWord, endWord, wordList);
    printSequences(sequences);

    return 0;
}