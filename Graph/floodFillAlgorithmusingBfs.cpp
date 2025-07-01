#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Implementation of the solve function 
void solve(vector<vector<int>> &image, vector<vector<int>> &imageCopy, int sr, int sc, int initialColor, int newColor, vector<int> &delrow, vector<int> &delcol) {
    imageCopy[sr][sc] = newColor;
    int n = image.size();
    int m = image[0].size();

    queue<pair<int, int>> q;
    q.push({sr, sc});

    while(!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];

            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && image[newrow][newcol] == initialColor && imageCopy[newrow][newcol] != newColor) {
                imageCopy[newrow][newcol] = newColor;
                q.push({newrow, newcol});
            }
        }
    }
}

// Function to perform flood fill using BFS
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
   int initialColor = image[sr][sc];

   // make a copy of the actual(input) data;
   vector<vector<int>> imageCopy = image;

   vector<int> delrow = {-1, 0, +1, 0};
   vector<int> delcol = {0, +1, 0, -1};

   solve(image, imageCopy, sr, sc, initialColor, newColor, delrow, delcol);

   return imageCopy;
}

// Helper function to print the image
void printImage(vector<vector<int>>& image) {
    for (const auto& row : image) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
}

int main() {
    /*
    Example:
    Input Image:
    1 1 1
    1 1 0    Starting from (1,1)
    1 0 1    Using BFS level by level

    Level 0: Change (1,1) to 2
    Level 1: Change all adjacent 1's to 2
    Continue until no more adjacent pixels of original color

    Output Image:
    2 2 2
    2 2 0
    2 0 1
    */

    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1; // starting row
    int sc = 1; // starting column
    int newColor = 2;

    cout << "Original Image:" << endl;
    printImage(image);

    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    cout << "\nImage after flood fill (using BFS):" << endl;
    printImage(result);

    return 0;
}