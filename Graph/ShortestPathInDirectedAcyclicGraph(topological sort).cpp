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
    // Function to find shortest paths from source to all vertices
    vector<int> shortestPath(vector<vector<Edge>>& adj, int V, int src) {
        // Your implementation goes here
    }

private:
    // Helper function for topological sort using DFS
    void topoSort(vector<vector<Edge>>& adj, int v, vector<bool>& visited, stack<int>& st) {
        // Your implementation goes here
    }
};

// Helper function to add directed edge with weight
void addEdge(vector<vector<Edge>>& adj, int u, int v, int weight) {
    adj[u].push_back(Edge(v, weight));
}

int main() {
    /*
    Example DAG:
           2
    0 --------→ 1
    |           ↑ \
    |3          |  \ 6
    ↓      1    |   ↘
    2 --------→ 3     4

    Source vertex: 0
    Expected shortest distances:
    0 to 0: 0
    0 to 1: 2
    0 to 2: 3
    0 to 3: 4 (through 2)
    0 to 4: 8 (through 1)
    */

    int V = 5;  // Number of vertices
    vector<vector<Edge>> adj(V);

    // Adding edges and weights
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 2, 3);
    addEdge(adj, 2, 3, 1);
    addEdge(adj, 3, 1, 1);
    addEdge(adj, 1, 4, 6);

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

    return 0;
}