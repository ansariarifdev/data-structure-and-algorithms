#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to detect cycle in an undirected graph using BFS
bool checkCycleBFS(vector<vector<int>>& adj, int start, vector<bool>& visited) {
    // Your implementation goes here
}

bool isCycle(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            if(checkCycleBFS(adj, i, visited))
                return true;
        }
    }
    return false;
}

// Helper function to add edge in the graph
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    /*
    Example Graph:
        0 --- 1
        |     |
        2 --- 3

    This graph contains a cycle: 0-1-3-2-0
    
    Example Graph without cycle:
        0 --- 1
        |     
        2     3
    */

    // Test case 1: Graph with cycle
    int V1 = 4;
    vector<vector<int>> adj1(V1);
    
    addEdge(adj1, 0, 1);
    addEdge(adj1, 1, 3);
    addEdge(adj1, 3, 2);
    addEdge(adj1, 2, 0);

    cout << "Graph 1 " << (isCycle(adj1, V1) ? "contains" : "doesn't contain") 
         << " a cycle" << endl;

    // Test case 2: Graph without cycle
    int V2 = 4;
    vector<vector<int>> adj2(V2);
    
    addEdge(adj2, 0, 1);
    addEdge(adj2, 0, 2);

    cout << "Graph 2 " << (isCycle(adj2, V2) ? "contains" : "doesn't contain") 
         << " a cycle" << endl;

    return 0;
}