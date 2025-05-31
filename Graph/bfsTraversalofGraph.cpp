#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS traversal of graph
vector<int> bfsTraversal(vector<vector<int>>& adj, int V, int startVertex) {
    // Your implementation goes here
}

// Helper function to add edge in the graph
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Remove this line for directed graph
}

int main() {
    /*
    Example Graph:
        0 --- 1
        |     |
        2 --- 3
        |
        4

    Expected BFS traversal starting from vertex 0:
    0, 1, 2, 3, 4
    (Level by level traversal)
    */

    int V = 5; // Number of vertices
    vector<vector<int>> adj(V);

    // Adding edges
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);

    int startVertex = 0;
    vector<int> bfs = bfsTraversal(adj, V, startVertex);

    cout << "BFS traversal starting from vertex " << startVertex << ":\n";
    for (int i : bfs) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}