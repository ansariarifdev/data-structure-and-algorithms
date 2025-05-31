#include <bits/stdc++.h>
using namespace std;

// Structure for weighted edge
struct Edge {
    int dest;
    int weight;
    Edge(int d, int w) : dest(d), weight(w) {}
};

class Solution {
public:
    // Function to find shortest paths from source using Dijkstra's algorithm
    vector<int> shortestPath(vector<vector<Edge>>& adj, int V, int src) {
        // Your implementation goes here
    }
};

// Helper function to add undirected weighted edge
void addEdge(vector<vector<Edge>>& adj, int u, int v, int weight) {
    adj[u].push_back(Edge(v, weight));
    adj[v].push_back(Edge(u, weight)); // Remove for directed graph
}

int main() {
    /*
    Example Graph:
          4
    0 -------- 1
    |  \       | \
    |   \2     |  \ 3
    8    \     2   2
    |     \    |   /
    |      \   |  /
    2 ------- 3 /
         1
    
    Source vertex: 0
    Expected shortest distances:
    0 to 0: 0
    0 to 1: 4
    0 to 2: 8
    0 to 3: 2
    */

    int V = 4;  // Number of vertices
    vector<vector<Edge>> adj(V);

    // Adding edges with weights
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 2, 8);
    addEdge(adj, 0, 3, 2);
    addEdge(adj, 1, 3, 2);
    addEdge(adj, 2, 3, 1);

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
    V = 3;
    vector<vector<Edge>> adj2(V);
    addEdge(adj2, 0, 1, 5);
    // Vertex 2 is disconnected

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