#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform Kahn's algorithm for topological sorting
vector<int> topoSort(vector<vector<int>>& adj, int V) {
    vector<int> indegree(V, 0);

    for(int i = 0; i < V; i++) {
        for(auto neighbour: adj[i]) {
            indegree[neighbour]++;
        }
    }

    vector<int> ans;
    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int currentNode = q.front();
        q.pop();
        ans.push_back(currentNode);

        for(auto neighbour: adj[currentNode]) {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    return ans;

}

// Helper function to add directed edge
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
}

int main() {
    /*
    Example: Course Prerequisites
    0 → 1 → 3
      ↘ 2 ↗
    
    Valid Order: 0, 2, 1, 3
    (Course 0 must be taken before 1 and 2)
    (Courses 1 and 2 must be taken before 3)
    */

    int V = 4;
    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);

    vector<int> result = topoSort(adj, V);

    cout << "Topological Sort using Kahn's Algorithm: ";
    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;

    // Test case 2: Linear dependency
    int V2 = 3;
    vector<vector<int>> adj2(V2);
    addEdge(adj2, 0, 1);
    addEdge(adj2, 1, 2);

    cout << "\nTest Case 2 (Linear Dependencies):" << endl;
    result = topoSort(adj2, V2);
    cout << "Topological Sort: ";
    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}