#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to detect cycle in directed graph using BFS (Kahn's Algorithm)
bool isCyclic(vector<vector<int>>& adj, int V) {
    // Your implementation goes here
}

// Helper function to add directed edge
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v); // Only add edge from u to v (directed)
}

int main() {
    /*
    Example 1: Directed Graph with cycle
    0 → 1 → 2
        ↑   ↓
        3 ← 4

    Forms cycle: 1 → 2 → 4 → 3 → 1

    Example 2: Directed Graph without cycle
    0 → 1 → 3
        ↓
        2
    */

    // Test case 1: Graph with cycle
    int V1 = 5;
    vector<vector<int>> adj1(V1);
    
    addEdge(adj1, 0, 1);
    addEdge(adj1, 1, 2);
    addEdge(adj1, 2, 4);
    addEdge(adj1, 4, 3);
    addEdge(adj1, 3, 1);  // Creates cycle

    cout << "Graph 1 " << (isCyclic(adj1, V1) ? "contains" : "doesn't contain") 
         << " a cycle" << endl;

    // Test case 2: Graph without cycle
    int V2 = 4;
    vector<vector<int>> adj2(V2);
    
    addEdge(adj2, 0, 1);
    addEdge(adj2, 1, 2);
    addEdge(adj2, 1, 3);

    cout << "Graph 2 " << (isCyclic(adj2, V2) ? "contains" : "doesn't contain") 
         << " a cycle" << endl;

    return 0;
}