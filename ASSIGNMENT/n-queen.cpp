#include<bits/stdc++.h>

class Solution {
public:
    vector<vector<string>> res;
    
    void solve(int row, int n, vector<string>& board,
               vector<int>& col, vector<int>& diag1, vector<int>& diag2) {
        
        if(row == n) {
            res.push_back(board);
            return;
        }
        
        for(int c = 0; c < n; c++) {
            if(col[c] || diag1[row + c] || diag2[row - c + n - 1]) continue;
            
            board[row][c] = 'Q';
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = 1;
            
            solve(row + 1, n, board, col, diag1, diag2);
            
            board[row][c] = '.';
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = 0;
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<int> col(n, 0), diag1(2*n, 0), diag2(2*n, 0);
        
        solve(0, n, board, col, diag1, diag2);
        return res;
    }
};


int main() {
    int n;
    cout << "Enter value of N: ";
    cin >> n;

    Solution obj;
    vector<vector<string>> solutions = obj.solveNQueens(n);

    if(solutions.empty()) {
        cout << "No solutions exist.\n";
        return 0;
    }

    int count = 0;

    for(auto &board : solutions) {
        cout << "Solution " << ++count << ":\n";
        for(auto &row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

    cout << "Total number of solutions: " << solutions.size() << endl;

    return 0;
}