#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Implementation of the solve function 
void solve(vector<vector<int>> &adj, int i, vector<bool> &visited, vector<int> &ans) {
    queue<int> q;
    q.push(i);

    while(!q.empty()) {
        int currentNode = q.front();
        q.pop();

        visited[currentNode] = true;
        ans.push_back(currentNode);

        for(auto element: adj[currentNode]) {
            if(!visited[element]) {
                visited[element] = true;
                q.push(element);
            }
        }
    }
}

// Function to perform BFS traversal of graph
vector<int> bfsTraversal(vector<vector<int>>& adj, int V, int startVertex) {
    // Your implementation goes here
    vector<bool> visited(adj.size(), false);
    vector<int> ans;

    for(int i = 0; i < adj.size(); i++) {
        if(!visited[i]) {
            solve(adj, i, visited, ans);
        }
    }
    return ans;
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

/*

    // this code if you want to start from a given source node

    the above provided code is for general case(consider to cover all the components, disconnected also)
    
    if (!visited[startVertex]) {
    solve(adj, startVertex, visited, ans);
}
*/