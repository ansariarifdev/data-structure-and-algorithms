#include <iostream>
#include <vector>
using namespace std;

// Implementation of the solve function 
bool solve(int currentNode, int parent, vector<bool> &visited, vector<vector<int>> &adj) {

    visited[currentNode] = true;

    for(auto neighbour: adj[currentNode]) {
        if(!visited[neighbour]) {
            if(solve(neighbour, currentNode, visited, adj) == true) {
                return true;
            }
        } else {
            if(neighbour != parent) {
                return true;
            }
        }
    }
    return false;
}

// Implementation of the isCycle function 
bool isCycle(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            // return true if cycle is present else false
            if(solve(i, -1, visited, adj) == true) {
                return true;
            }
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
    Example Graph with cycle:
        0 --- 1
        |     |
        2 --- 3

    DFS path that detects cycle: 
    0 -> 1 -> 3 -> 2 -> 0 (back edge creates cycle)

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