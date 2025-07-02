#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    // Implementation of the solve function(using bfs)
    bool solve(int i, vector<int> &color, vector<vector<int>> &graph) {
        color[i] = 0;
        queue<int> q;
        q.push(i);

        while(!q.empty()) {
            int currentNode = q.front();
            q.pop();

            for(auto neighbour: graph[currentNode]) {
                if(color[neighbour] == -1) {
                    color[neighbour] = 1 - color[currentNode];
                    q.push(neighbour);
                } else if(color[neighbour] == color[currentNode]) {
                    return false;
                }
            }
        }
        return true;
    }
    
public:
    // Function to check if a graph is bipartite
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);

        for(int i = 0 ; i < graph.size(); i++) {
            if(color[i] == -1) {
                if(solve(i, color, graph) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;

    // ---------- Test Case 1 ----------
    vector<vector<int>> graph1 = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    /*
    Expected Output: 1 (true)
    This graph is bipartite.
    */

    cout << "Is graph1 bipartite? " << solution.isBipartite(graph1) << endl;

    // ---------- Test Case 2 ----------
    vector<vector<int>> graph2 = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}
    };

    /*
    Expected Output: 0 (false)
    This graph is NOT bipartite.
    */

    cout << "Is graph2 bipartite? " << solution.isBipartite(graph2) << endl;

    return 0;
}
