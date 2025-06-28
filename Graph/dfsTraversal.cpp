#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS traversal recursively
void dfs(vector<vector<int>>& adj, int vertex, vector<bool>& visited, vector<int>& result) {
    // Your implementation goes here
    if(visited[vertex]) {
        return ;
    }

    visited[vertex] = true;
    result.push_back(vertex);

    for(auto element: adj[vertex]) {
        dfs(adj, element, visited, result);
    }
}

// Function to initiate DFS traversal of graph
vector<int> dfsTraversal(vector<vector<int>>& adj, int V, int startVertex) {
    // Your implementation goes here
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> result;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(adj, i, visited, result);
        }
    }
    return result;
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

    Expected DFS traversal starting from vertex 0:
    0, 1, 3, 2, 4
    (Depth-first exploration)
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
    vector<int> dfs = dfsTraversal(adj, V, startVertex);

    cout << "DFS traversal starting from vertex " << startVertex << ":\n";
    for (int i : dfs) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}