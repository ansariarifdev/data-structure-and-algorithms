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
    // Function to find shortest paths from source using Dijkstra's algorithm with set
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

    Using set instead of priority_queue for:
    - Better handling of distance updates
    - Automatic sorting of vertices by distance
    - Efficient removal of processed vertices
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

    // Test case 2: Graph with multiple paths
    V = 5;
    vector<vector<Edge>> adj2(V);
    addEdge(adj2, 0, 1, 2);
    addEdge(adj2, 0, 2, 4);
    addEdge(adj2, 1, 2, 1);
    addEdge(adj2, 1, 3, 7);
    addEdge(adj2, 2, 4, 3);
    addEdge(adj2, 3, 4, 1);

    cout << "\nTest Case 2 (Multiple Paths):\n";
    dist = sol.shortestPath(adj2, V, 0);
    for(int i = 0; i < V; i++) {
        if(dist[i] == INT_MAX)
            cout << "0 to " << i << ": INFINITY\n";
        else
            cout << "0 to " << i << ": " << dist[i] << "\n";
    }

    return 0;
}