#include <iostream>
#include <vector>
using namespace std;

// Implementation of the solve function 
bool solve(int currentNode, vector<bool> &currentPath, vector<bool>& visited, vector<vector<int>> &adj) {
    visited[currentNode] = true;
    currentPath[currentNode] = true;

    for(auto neighbour: adj[currentNode]) {
        if(!visited[neighbour]) {
            if(solve(neighbour, currentPath, visited, adj) == true) {
                return true;
            }
        } else {
            if(currentPath[neighbour] == true) {
                return true;
            }
        }
    }
    return false;
}

bool isCyclic(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            vector<bool> currentPath(V, false);
            if(solve(i, currentPath, visited, adj) == true) {
                return true;
            }
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