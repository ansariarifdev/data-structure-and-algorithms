#include <bits/stdc++.h>
using namespace std;

// Function to perform DFS for topological sort
void dfs(vector<vector<int>>& adj, int vertex, vector<bool>& visited, stack<int>& st) {
    // Your implementation goes here
}

// Function to perform topological sort
vector<int> topologicalSort(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    stack<int> st;
    vector<int> result;
    
    // Your implementation goes here
    
    return result;
}

// Helper function to add directed edge
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v); // Only add edge from u to v (directed)
}

int main() {
    /*
    Example: Dependencies in a build system
    Consider vertices as tasks and edges as dependencies
    
    5 → 0 ← 4
    ↓   ↑   ↑
    2 → 3 → 1

    Valid Topological Sort: 5 4 2 3 1 0
    (Note: Multiple valid orderings may exist)
    */

    int V = 6;  // Number of vertices
    vector<vector<int>> adj(V);
    
    // Adding edges (dependencies)
    addEdge(adj, 5, 0);
    addEdge(adj, 5, 2);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);
    addEdge(adj, 3, 0);

    vector<int> result = topologicalSort(adj, V);
    
    cout << "Topological Sort Order: ";
    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;

    // Test case 2: Linear dependency chain
    int V2 = 4;
    vector<vector<int>> adj2(V2);
    addEdge(adj2, 3, 2);
    addEdge(adj2, 2, 1);
    addEdge(adj2, 1, 0);

    cout << "\nTest Case 2 (Linear Chain):" << endl;
    result = topologicalSort(adj2, V2);
    cout << "Topological Sort Order: ";
    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}