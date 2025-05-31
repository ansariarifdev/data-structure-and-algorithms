#include <bits/stdc++.h>
using namespace std;

// Function to detect cycle in a directed graph using DFS
bool checkCycleDFS(vector<vector<int>>& adj, int vertex, vector<bool>& visited, vector<bool>& recursionStack) {
    // Your implementation goes here
}

bool isCyclic(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    vector<bool> recursionStack(V, false);
    
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            if(checkCycleDFS(adj, i, visited, recursionStack))
                return true;
        }
    }
    return false;
}

// Helper function to add directed edge in the graph
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v); // Only add edge from u to v (directed)
}

int main() {
    /*
    Example 1: Directed Graph with cycle
    0 → 1 → 2 → 3
        ↑_______|
    
    Forms cycle: 1 → 2 → 3 → 1

    Example 2: Directed Graph without cycle
    0 → 1 → 2
        ↓
        3
    */

    // Test case 1: Graph with cycle
    int V1 = 4;
    vector<vector<int>> adj1(V1);
    
    addEdge(adj1, 0, 1);
    addEdge(adj1, 1, 2);
    addEdge(adj1, 2, 3);
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