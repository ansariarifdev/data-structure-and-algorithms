#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:

    void dfs(int row, int col, int n, int m, vector<vector<char>> &board, vector<vector<int>> &visited) {
        visited[row][col] = 1;

        vector<int> delrow = {-1, 0, +1, 0};
        vector<int> delcol = {0, +1, 0, -1};

        for(int i = 0; i < 3; i++) {
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];

            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && board[newrow][newcol] == 'O' && visited[newrow][newcol] == 0) {
                dfs(newrow, newcol, n, m, board, visited);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        // first row and last row
        for(int j = 0; j < m; j++) {
            // first row
            if(board[0][j] == 'O') {
                visited[0][j] = 1;
                dfs(0, j, n, m, board, visited);
            }

            if(board[n-1][j] == 'O') {
                visited[n-1][j] = 1;
                dfs(n-1, j, n, m, board, visited);
            }
        }

        // first col and last col
        for(int i = 0; i < n; i++) {
            // first col
            if(board[i][0] == 'O') {
                visited[i][0] = 1;
                dfs(i, 0, n, m, board, visited);
            }

            // last col
            if(board[i][m-1] == 'O') {
                visited[i][m-1] = 1;
                dfs(i, m-1, n, m, board, visited);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' && visited[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

void printBoard(const vector<vector<char>>& board) {
    for (auto row : board) {
        for (char c : row)
            cout << c << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // ---------- Test Case 1 ----------
    vector<vector<char>> board1 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    /*
    Expected Output 1:
    X X X X
    X X X X
    X X X X
    X O X X
    */

    solution.solve(board1);
    cout << "Output 1:\n";
    printBoard(board1);

    // ---------- Test Case 2 ----------
    vector<vector<char>> board2 = {
        {'X', 'O', 'X'},
        {'O', 'O', 'O'},
        {'X', 'O', 'X'}
    };

    /*
    Expected Output 2:
    X O X
    O O O
    X O X
    */

    solution.solve(board2);
    cout << "Output 2:\n";
    printBoard(board2);

    return 0;
}
