class Solution {
public:
    vector<vector<string>> result;
    vector<string> board;
    int n;

    bool isSafe(int row, int col) {
        //uppr ka column
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') return false;
        }

        // left upper ka diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') return false;
        }

        // right upper ka diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(int row) {
        if (row == n) {
            result.emplace_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col)) {
                board[row][col] = 'Q';
                solve(row + 1);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int N) {
        n = N;
        result.clear();
        board = vector<string>(n, string(n, '.'));

        solve(0);
        return result;
    }
};
