#include <iostream>
#include <vector>
using namespace std;

// Implementation of the solve function 
void solve(vector<vector<int>> &image, vector<vector<int>> &imageCopy, int sr, int sc, vector<int> &delrow, vector<int> &delcol, int initialColor, int newColor) {
    imageCopy[sr][sc] = newColor;

    int n = image.size();
    int m = image[0].size();

    for(int i = 0; i < 4; i++) {
        int newrow = sr + delrow[i];
        int newcol = sc + delcol[i];

        if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && image[newrow][newcol] == initialColor && imageCopy[newrow][newcol] != newColor) {
            solve(image, imageCopy, newrow, newcol, delrow, delcol, initialColor, newColor);
        }
    }
}
// Function to flood fill the image
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    // Your implementation goes here
    int initialColor = image[sr][sc];
    vector<vector<int>> imageCopy = image;

    vector<int> delrow = {-1, 0, +1, 0};
    vector<int> delcol = {0, +1, 0, -1};

    solve(image, imageCopy, sr, sc, delrow, delcol, initialColor, newColor);
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