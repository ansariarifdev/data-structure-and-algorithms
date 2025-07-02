#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to check if it's possible to finish all courses
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Your implementation goes here
        // done something
    }
    
    // Function to return the order of courses to take
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Your implementation goes here
    }
};

int main() {
    /*
    Example:
    numCourses = 4
    prerequisites = [[1,0], [2,0], [3,1], [3,2]]
    
    Represents:
    0 → 1 → 3
      ↘ 2 ↗
    
    Course Schedule I: Return true if possible to finish all courses
    Course Schedule II: Return valid order to take courses
    */

    Solution sol;
    
    // Test case 1: Possible to complete
    int numCourses1 = 4;
    vector<vector<int>> prerequisites1 = {{1,0}, {2,0}, {3,1}, {3,2}};
    
    bool possible = sol.canFinish(numCourses1, prerequisites1);
    cout << "Test Case 1:" << endl;
    cout << "Can finish all courses? " << (possible ? "Yes" : "No") << endl;
    
    if (possible) {
        vector<int> order = sol.findOrder(numCourses1, prerequisites1);
        cout << "Course order: ";
        for (int course : order) {
            cout << course << " ";
        }
        cout << endl;
    }

    // Test case 2: Impossible due to cycle
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1,0}, {0,1}};
    
    cout << "\nTest Case 2:" << endl;
    possible = sol.canFinish(numCourses2, prerequisites2);
    cout << "Can finish all courses? " << (possible ? "Yes" : "No") << endl;

    return 0;
}