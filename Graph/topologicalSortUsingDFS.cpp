#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Implementation of the solve function
void solve(int currentNode, vector<int> &visited, stack<int> &st, vector<vector<int>> &adj) {
    visited[currentNode] = 1;

    for(auto neighbour: adj[currentNode]) {
        if(!visited[neighbour]) {
            solve(neighbour, visited, st, adj);
        }
    }
    st.push(currentNode);
}

// Function to perform topological sort
vector<int> topologicalSort(vector<vector<int>>& adj, int V) {
    vector<int> visited(V, 0);
    stack<int> st;

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            solve(i, visited, st, adj);
        }
    }

    vector<int> ans;

    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

// Helper function to add directed edge
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v); // Only add edge from u to v (directed)
}

int main() {
    /*
    Example: Dependencies in a build system
    Consider vertices as tasks and edges as dependencies
    
    5 → 0 ← 4
    ↓   ↑   ↑
    2 → 3 → 1

    Valid Topological Sort: 5 4 2 3 1 0
    (Note: Multiple valid orderings may exist)
    */

    int V = 6;  // Number of vertices
    vector<vector<int>> adj(V);
    
    // Adding edges (dependencies)
    addEdge(adj, 5, 0);
    addEdge(adj, 5, 2);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);
    addEdge(adj, 3, 0);

    vector<int> result = topologicalSort(adj, V);
    
    cout << "Topological Sort Order: ";
    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;

    // Test case 2: Linear dependency chain
    int V2 = 4;
    vector<vector<int>> adj2(V2);
    addEdge(adj2, 3, 2);
    addEdge(adj2, 2, 1);
    addEdge(adj2, 1, 0);

    cout << "\nTest Case 2 (Linear Chain):" << endl;
    result = topologicalSort(adj2, V2);
    cout << "Topological Sort Order: ";
    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}