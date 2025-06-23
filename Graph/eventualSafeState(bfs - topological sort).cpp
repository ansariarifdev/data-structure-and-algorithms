#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Function to find eventual safe states using BFS
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    // Your implementation goes here
}

int main() {
    /*
    Example:
    Graph represented by adjacency list where graph[i] contains nodes that node i points to
    
    Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
    Visualization:
    0 → 1 → 2 → 5
      ↘ ↓   ↓
        3 ← 4
    
    Safe nodes: 2, 4, 5, 6
    (Nodes that eventually end up at terminal nodes)
    */

    // Test Case 1: Graph with safe and unsafe nodes
    vector<vector<int>> graph = {
        {1,2},  // node 0
        {2,3},  // node 1
        {5},    // node 2
        {0},    // node 3
        {5},    // node 4
        {},     // node 5 (terminal)
        {}      // node 6 (terminal)
    };

    cout << "Finding safe nodes..." << endl;
    vector<int> safeNodes = eventualSafeNodes(graph);
    
    cout << "Safe nodes in ascending order: ";
    for (int node : safeNodes) {
        cout << node << " ";
    }
    cout << endl;

    // Test Case 2: Graph with cycle
    vector<vector<int>> graph2 = {
        {1},    // node 0
        {2},    // node 1
        {1}     // node 2 (forms cycle with 1)
    };

    cout << "\nTest Case 2 (Graph with cycle):" << endl;
    safeNodes = eventualSafeNodes(graph2);
    cout << "Safe nodes: ";
    for (int node : safeNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}