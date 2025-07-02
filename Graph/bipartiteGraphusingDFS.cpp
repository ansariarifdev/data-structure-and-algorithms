#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    // Implementation of the solve function(dfs)
    bool solve(int i, int initialColor, vector<int> &color, const vector<vector<int>> &graph) {
        color[i] = initialColor;

        for(auto neighbour: graph[i]) {
            if(color[neighbour] == -1) {
                if(solve(neighbour, 1 - color[i], color, graph) == false) {
                    return false;
                }
            } else if(color[i] == color[neighbour]) {
                return false;
            }
        }
        return true;
    }
public:
    // Function to check if a graph is bipartite
    bool isBipartite(const vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        int n = graph.size();

        for(int i = 0; i < n; i++) {
            if(color[i] == -1 && solve(i, 0, color, graph) == false) {
                return false;
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
    Expected Output: true
    This graph is bipartite.
    */

    cout << "Is graph1 bipartite? " << boolalpha << solution.isBipartite(graph1) << endl;

    // ---------- Test Case 2 ----------
    vector<vector<int>> graph2 = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}
    };

    /*
    Expected Output: false
    This graph is NOT bipartite.
    */

    cout << "Is graph2 bipartite? " << boolalpha << solution.isBipartite(graph2) << endl;

    return 0;
}
