#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    // Function to find shortest path to all vertices from source
    vector<int> shortestPath(vector<vector<int>>& adj, int V, int src) {
        // Your implementation goes here
    }
};

// Helper function to add undirected edge
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    /*
    Example Undirected Graph:
    0 --- 1 --- 2
    |     |     |
    3 --- 4 --- 5

    Source vertex: 0
    Expected distances:
    0 to 0: 0
    0 to 1: 1
    0 to 2: 2
    0 to 3: 1
    0 to 4: 2
    0 to 5: 3
    */

    int V = 6;  // Number of vertices
    vector<vector<int>> adj(V);

    // Adding edges (undirected)
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);

    Solution sol;
    int src = 0;
    vector<int> dist = sol.shortestPath(adj, V, src);

    cout << "Shortest distances from source " << src << ":\n";
    for(int i = 0; i < V; i++) {
        if(dist[i] == INT_MAX)
            cout << src << " to " << i << ": INFINITY\n";
        else
            cout << src << " to " << i << ": " << dist[i] << "\n";
    }

    // Test case 2: Disconnected graph
    V = 4;
    vector<vector<int>> adj2(V);
    addEdge(adj2, 0, 1);
    addEdge(adj2, 2, 3);

    cout << "\nTest Case 2 (Disconnected Graph):\n";
    dist = sol.shortestPath(adj2, V, 0);
    for(int i = 0; i < V; i++) {
        if(dist[i] == INT_MAX)
            cout << "0 to " << i << ": INFINITY\n";
        else
            cout << "0 to " << i << ": " << dist[i] << "\n";
    }

    return 0;
}