#include <iostream>
#include <vector>
using namespace std;

// Function to perform flood fill using DFS
void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor) {
    // Your implementation goes here
}

// Function to flood fill the image
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
    1 1 0
    1 0 1

    Starting pixel (sr,sc) = (1,1)
    New color = 2

    Output Image:
    2 2 2
    2 2 0
    2 0 1

    Explanation:
    - Starting from position (1,1) with color 1
    - Replace all connected pixels of same color with 2
    - Diagonally connected pixels are not considered
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

    cout << "\nImage after flood fill:" << endl;
    printImage(result);

    return 0;
}