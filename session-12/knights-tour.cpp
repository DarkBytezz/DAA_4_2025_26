class Solution {
public:
    
    int dx[8] = {2,1,-1,-2,-2,-1,1,2};
    int dy[8] = {1,2,2,1,-1,-2,-2,-1};
    
    bool isValid(int x, int y, int n, vector<vector<int>>& board){
        return (x>=0 && y>=0 && x<n && y<n && board[x][y] == -1);
    }
    
    bool solve(int x, int y, int moveCount, int n, vector<vector<int>>& board){
        
        if(moveCount == n*n)
            return true;
        
        for(int k=0;k<8;k++){
            
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if(isValid(nx, ny, n, board)){
                
                board[nx][ny] = moveCount;
                
                if(solve(nx, ny, moveCount+1, n, board))
                    return true;
                
                board[nx][ny] = -1; 
            }
        }
        
        return false;
    }
    
    vector<vector<int>> knightTour(int n) {
        
        vector<vector<int>> board(n, vector<int>(n, -1));
        
        board[0][0] = 0;
        
        if(solve(0, 0, 1, n, board))
            return board;
        
        return {};
    }
};
