#include <bits/stdc++.h>
using namespace std;

// Function to perform flood fill using BFS
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    // Your implementation goes here
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